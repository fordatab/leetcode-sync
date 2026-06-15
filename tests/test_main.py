"""Unit tests for src.main (the orchestrator).

The external boundaries — LeetCode's API and Claude — are patched. Git,
state.json and the filesystem are exercised for real against a throwaway
repo with a bare remote, so the end-to-end flow (folders, backdated
commits, push, idempotency) is genuinely verified.
"""

from __future__ import annotations

import copy
import json
import os
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest import mock

from src import leetcode, main


def _git(repo: Path, *args: str) -> str:
    result = subprocess.run(
        ["git", "-C", str(repo), *args],
        capture_output=True,
        text=True,
        encoding="utf-8",
        check=True,
    )
    return result.stdout.strip()


# --- Fake LeetCode / Claude data -------------------------------------------

RECENT = [
    # Deliberately out of chronological order to prove run() sorts them.
    {"id": "202", "title": "Add Two Numbers", "titleSlug": "add-two-numbers",
     "timestamp": "1700100000"},
    {"id": "201", "title": "Two Sum", "titleSlug": "two-sum",
     "timestamp": "1700000000"},
]

DETAILS = {
    201: {
        "runtime": "52", "runtimeDisplay": "52 ms",
        "memory": "16800000", "memoryDisplay": "16.8 MB",
        "code": "class Solution:\n    def twoSum(self, nums, target): ...\n",
        "lang": {"name": "python3", "verboseName": "Python3"},
        "question": {
            "questionId": "1", "title": "Two Sum", "titleSlug": "two-sum",
            "difficulty": "Easy", "content": "<p>Find two numbers.</p>",
        },
        "timestamp": "1700000000",
    },
    202: {
        "runtime": "88", "runtimeDisplay": "88 ms",
        "memory": "20100000", "memoryDisplay": "20.1 MB",
        "code": "// add two numbers\nListNode* addTwoNumbers(...) {}\n",
        "lang": {"name": "cpp", "verboseName": "C++"},
        "question": {
            "questionId": "2", "title": "Add Two Numbers", "titleSlug": "add-two-numbers",
            "difficulty": "Medium", "content": "<p>Add linked lists.</p>",
        },
        "timestamp": "1700100000",
    },
    # Same problem as 201 (questionId 1) but a different language.
    203: {
        "runtime": "40", "runtimeDisplay": "40 ms",
        "memory": "8000000", "memoryDisplay": "8.0 MB",
        "code": "int* twoSum(...) {}\n",
        "lang": {"name": "c", "verboseName": "C"},
        "question": {
            "questionId": "1", "title": "Two Sum", "titleSlug": "two-sum",
            "difficulty": "Easy", "content": "<p>Find two numbers.</p>",
        },
        "timestamp": "1700200000",
    },
}


def fake_details(submission_id, **kwargs):
    return copy.deepcopy(DETAILS[int(submission_id)])


def fake_enrich(details, **kwargs):
    question = details["question"]
    padded = str(question["questionId"]).zfill(4)
    return {
        "problem_summary": f"Paraphrased summary of {question['title']}.",
        "approach": f"Approach for {question['titleSlug']} using a hash map.",
        "complexity": {"time": "O(n)", "space": "O(n)"},
        "tags": ["array", "hash-table"],
        "commit_message": f"solve({padded}): {question['titleSlug']}",
    }


# --- Test harness -----------------------------------------------------------

class MainTestBase(unittest.TestCase):
    def setUp(self):
        self.root = Path(tempfile.mkdtemp())
        self.addCleanup(lambda: shutil.rmtree(self.root, ignore_errors=True))

        self.repo = self.root / "repo"
        self.repo.mkdir()
        _git(self.repo, "init")
        _git(self.repo, "config", "user.name", "Test Runner")
        _git(self.repo, "config", "user.email", "test@example.com")
        _git(self.repo, "config", "commit.gpgsign", "false")

        # An initial commit so the branch exists, then a bare remote with
        # upstream tracking so plain `git push` works (mirrors a CI checkout).
        (self.repo / ".gitkeep").write_text("", encoding="utf-8")
        _git(self.repo, "add", "-A")
        _git(self.repo, "commit", "-m", "init")
        self.remote = self.root / "remote.git"
        subprocess.run(
            ["git", "init", "--bare", str(self.remote)],
            capture_output=True, text=True, check=True,
        )
        _git(self.repo, "remote", "add", "origin", str(self.remote))
        self.branch = _git(self.repo, "branch", "--show-current")
        _git(self.repo, "push", "-u", "origin", self.branch)

        # Point state.json inside the repo so it is committed like in prod.
        self.state_path = self.repo / "state.json"
        env = mock.patch.dict(
            os.environ, {"LEETCODE_SYNC_STATE_PATH": str(self.state_path)}
        )
        env.start()
        self.addCleanup(env.stop)

    def _patch_apis(self, recent=RECENT, details=fake_details, enrich=fake_enrich):
        """Patch the LeetCode + Claude boundaries; returns the three mocks."""
        p_recent = mock.patch(
            "src.leetcode.fetch_recent_submissions", return_value=copy.deepcopy(recent)
        )
        p_details = mock.patch(
            "src.leetcode.fetch_submission_details", side_effect=details
        )
        p_enrich = mock.patch("src.ai_agent.enrich_submission", side_effect=enrich)
        m_recent = p_recent.start()
        m_details = p_details.start()
        m_enrich = p_enrich.start()
        self.addCleanup(p_recent.stop)
        self.addCleanup(p_details.stop)
        self.addCleanup(p_enrich.stop)
        return m_recent, m_details, m_enrich

    def _commit_count(self) -> int:
        return int(_git(self.repo, "rev-list", "--count", "HEAD"))

    def _log(self, fmt: str) -> list[str]:
        return _git(self.repo, "log", f"--format={fmt}").splitlines()


# --- Tests ------------------------------------------------------------------

class HappyPathTests(MainTestBase):
    def test_creates_problem_folders_with_three_files(self):
        self._patch_apis()
        committed = main.run(repo_path=str(self.repo))
        self.assertEqual(committed, 2)

        two_sum = self.repo / "problems" / "0001-two-sum"
        add_two = self.repo / "problems" / "0002-add-two-numbers"
        for folder, ext in ((two_sum, "py"), (add_two, "cpp")):
            self.assertTrue((folder / "README.md").is_file())
            self.assertTrue((folder / f"solution.{ext}").is_file())
            self.assertTrue((folder / "metadata.json").is_file())

    def test_solution_file_holds_submitted_code(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        code = (self.repo / "problems" / "0001-two-sum" / "solution.py").read_text(
            encoding="utf-8"
        )
        self.assertEqual(code, DETAILS[201]["code"])

    def test_readme_has_expected_sections(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        readme = (self.repo / "problems" / "0001-two-sum" / "README.md").read_text(
            encoding="utf-8"
        )
        self.assertIn("# Two Sum", readme)
        self.assertIn("**Difficulty:** Easy", readme)
        self.assertIn("array, hash-table", readme)
        self.assertIn("Paraphrased summary of Two Sum.", readme)
        self.assertIn("- **Time:** O(n)", readme)
        self.assertIn("- Runtime: 52 ms", readme)

    def test_metadata_is_a_list_with_expected_fields(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        meta = json.loads(
            (self.repo / "problems" / "0001-two-sum" / "metadata.json").read_text(
                encoding="utf-8"
            )
        )
        self.assertIsInstance(meta, list)
        self.assertEqual(len(meta), 1)
        self.assertEqual(
            meta[0],
            {
                "submission_id": 201,
                "timestamp": 1700000000,
                "runtime": "52 ms",
                "memory": "16.8 MB",
                "language": "Python3",
                "difficulty": "Easy",
            },
        )

    def test_commits_are_backdated_to_submission_time(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        by_subject = dict(
            line.split(" ", 1)[::-1] for line in self._log("%at %s")
        )
        self.assertEqual(by_subject["solve(0001): two-sum"], "1700000000")
        self.assertEqual(by_subject["solve(0002): add-two-numbers"], "1700100000")

    def test_problems_committed_oldest_first(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        subjects = self._log("%s")
        # Newest first in git log: state commit, then 0002, then 0001.
        self.assertLess(
            subjects.index("solve(0002): add-two-numbers"),
            subjects.index("solve(0001): two-sum"),
        )

    def test_state_commit_is_not_backdated(self):
        self._patch_apis()
        before = int(__import__("time").time())
        main.run(repo_path=str(self.repo))
        after = int(__import__("time").time())
        state_at = int(_git(self.repo, "log", "-1", "--format=%at", "--grep=sync state"))
        self.assertGreaterEqual(state_at, before)
        self.assertLessEqual(state_at, after)

    def test_state_records_synced_ids(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        from src import state

        self.assertEqual(
            sorted(state.load_state()["synced_submission_ids"]), [201, 202]
        )

    def test_pushes_to_remote(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        self.assertEqual(
            _git(self.repo, "rev-parse", "HEAD"),
            _git(self.remote, "rev-parse", self.branch),
        )


class IdempotencyTests(MainTestBase):
    def test_rerun_makes_no_new_commits(self):
        self._patch_apis()
        main.run(repo_path=str(self.repo))
        count_after_first = self._commit_count()

        committed = main.run(repo_path=str(self.repo))
        self.assertEqual(committed, 0)
        self.assertEqual(self._commit_count(), count_after_first)

    def test_resubmission_commits_without_calling_claude(self):
        # Pre-create the solution file as if an earlier submission of the
        # same problem+language already landed. The new submission must
        # still produce a backdated commit (every accept counts), but Claude
        # is not re-invoked and the existing README is preserved.
        folder = self.repo / "problems" / "0001-two-sum"
        folder.mkdir(parents=True)
        (folder / "solution.py").write_text("stale", encoding="utf-8")
        (folder / "README.md").write_text("# original readme\n", encoding="utf-8")

        _, _, m_enrich = self._patch_apis()
        committed = main.run(repo_path=str(self.repo))

        # Claude only ran for the other (genuinely new) problem.
        self.assertEqual(m_enrich.call_count, 1)
        # Both submissions produced commits.
        self.assertEqual(committed, 2)
        from src import state

        self.assertIn(201, state.load_state()["synced_submission_ids"])
        # Solution file was overwritten with the new submission's code.
        self.assertEqual(
            (folder / "solution.py").read_text(encoding="utf-8"),
            DETAILS[201]["code"],
        )
        # README from the prior submission is preserved (no Claude regen).
        self.assertEqual(
            (folder / "README.md").read_text(encoding="utf-8"),
            "# original readme\n",
        )
        # Commit message uses the resubmit template, not Claude's solve(...).
        messages = self._log("%s")
        self.assertTrue(
            any(m.startswith("resubmit(0001): two-sum") for m in messages),
            messages,
        )


class MultiLanguageTests(MainTestBase):
    def test_second_language_lands_in_same_folder(self):
        recent = RECENT + [
            {"id": "203", "title": "Two Sum", "titleSlug": "two-sum",
             "timestamp": "1700200000"},
        ]
        self._patch_apis(recent=recent)
        main.run(repo_path=str(self.repo))

        folder = self.repo / "problems" / "0001-two-sum"
        self.assertTrue((folder / "solution.py").is_file())
        self.assertTrue((folder / "solution.c").is_file())

        meta = json.loads((folder / "metadata.json").read_text(encoding="utf-8"))
        self.assertEqual(
            sorted(e["submission_id"] for e in meta), [201, 203]
        )


class ResilienceTests(MainTestBase):
    def test_one_failing_submission_does_not_block_others(self):
        def flaky_enrich(details, **kwargs):
            if details["question"]["questionId"] == "1":
                raise RuntimeError("simulated Claude failure")
            return fake_enrich(details, **kwargs)

        self._patch_apis(enrich=flaky_enrich)
        # The good submission must still land and be pushed, but a partial
        # failure makes the run raise so the process exits non-zero.
        with self.assertRaises(main.SyncIncompleteError):
            main.run(repo_path=str(self.repo))

        self.assertTrue(
            (self.repo / "problems" / "0002-add-two-numbers").is_dir()
        )
        self.assertFalse((self.repo / "problems" / "0001-two-sum").exists())
        from src import state

        self.assertEqual(state.load_state()["synced_submission_ids"], [202])
        # The successful work was still pushed to the remote.
        self.assertEqual(
            _git(self.repo, "rev-parse", "HEAD"),
            _git(self.remote, "rev-parse", self.branch),
        )

    def test_partial_failure_exit_code_is_1(self):
        def flaky_enrich(details, **kwargs):
            if details["question"]["questionId"] == "1":
                raise RuntimeError("simulated Claude failure")
            return fake_enrich(details, **kwargs)

        self._patch_apis(enrich=flaky_enrich)
        self.assertEqual(main.main(["--repo-path", str(self.repo)]), 1)

    def test_all_details_null_is_treated_as_cookie_expiry(self):
        # Every detail fetch returning null while the recent list works is the
        # expired-session signature: run() must raise CookieExpiredError so the
        # operator gets the "refresh LEETCODE_SESSION" guidance (exit code 2).
        def null_details(submission_id, **kwargs):
            raise leetcode.SubmissionUnavailableError(
                f"submissionDetails was null for id={submission_id}"
            )

        self._patch_apis(details=null_details)
        with self.assertRaises(leetcode.CookieExpiredError):
            main.run(repo_path=str(self.repo))
        self.assertEqual(main.main(["--repo-path", str(self.repo)]), 2)
        # Nothing was committed or synced.
        from src import state

        self.assertEqual(state.load_state()["synced_submission_ids"], [])

    def test_cookie_expired_aborts_run(self):
        self._patch_apis()
        with mock.patch(
            "src.leetcode.fetch_recent_submissions",
            side_effect=leetcode.CookieExpiredError("401"),
        ):
            with self.assertRaises(leetcode.CookieExpiredError):
                main.run(repo_path=str(self.repo))

    def test_cookie_expired_exit_code_is_2(self):
        with mock.patch(
            "src.leetcode.fetch_recent_submissions",
            side_effect=leetcode.CookieExpiredError("401"),
        ):
            self.assertEqual(main.main(["--repo-path", str(self.repo)]), 2)


class PureHelperTests(unittest.TestCase):
    def test_ext_for_known_languages(self):
        self.assertEqual(main._ext_for_lang("python3"), "py")
        self.assertEqual(main._ext_for_lang("cpp"), "cpp")
        self.assertEqual(main._ext_for_lang("golang"), "go")
        self.assertEqual(main._ext_for_lang("JavaScript"), "js")

    def test_ext_for_unknown_language_falls_back(self):
        self.assertEqual(main._ext_for_lang("brainfuck"), "brainfuck")
        self.assertEqual(main._ext_for_lang(""), "txt")

    def test_folder_name_pads_id(self):
        self.assertEqual(
            main._folder_name({"questionId": "1", "titleSlug": "two-sum"}),
            "0001-two-sum",
        )
        self.assertEqual(
            main._folder_name({"questionId": "12345", "titleSlug": "big"}),
            "12345-big",
        )


if __name__ == "__main__":
    unittest.main()
