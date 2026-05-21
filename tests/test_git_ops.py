"""Unit tests for src.git_ops.

Each test runs against a throwaway git repo in a temp dir, so the real
`git` binary is exercised end to end (no mocking).
"""

from __future__ import annotations

import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

from src import git_ops


def _git(repo: Path, *args: str) -> str:
    """Run git in `repo`, assert success, return trimmed stdout."""
    result = subprocess.run(
        ["git", "-C", str(repo), *args],
        capture_output=True,
        text=True,
        encoding="utf-8",
        check=True,
    )
    return result.stdout.strip()


class GitOpsTestBase(unittest.TestCase):
    def setUp(self):
        self.root = Path(tempfile.mkdtemp())
        self.addCleanup(lambda: shutil.rmtree(self.root, ignore_errors=True))
        self.repo = self.root / "repo"
        self.repo.mkdir()
        _git(self.repo, "init")
        # Pin identity + disable signing so commits don't depend on the
        # host's global git config.
        _git(self.repo, "config", "user.name", "Test Runner")
        _git(self.repo, "config", "user.email", "test@example.com")
        _git(self.repo, "config", "commit.gpgsign", "false")

    def _write(self, name: str, content: str = "x") -> None:
        (self.repo / name).write_text(content, encoding="utf-8")

    def _make_bare_remote(self) -> Path:
        remote = self.root / "remote.git"
        subprocess.run(
            ["git", "init", "--bare", str(remote)],
            capture_output=True,
            text=True,
            check=True,
        )
        return remote


class ConfigureGitIdentityTests(GitOpsTestBase):
    def test_sets_name_and_email(self):
        git_ops.configure_git_identity(
            "LeetCode Bot", "bot@users.noreply.github.com", repo_path=str(self.repo)
        )
        self.assertEqual(_git(self.repo, "config", "--get", "user.name"), "LeetCode Bot")
        self.assertEqual(
            _git(self.repo, "config", "--get", "user.email"),
            "bot@users.noreply.github.com",
        )

    def test_overwrites_existing_identity(self):
        git_ops.configure_git_identity("First", "first@x.com", repo_path=str(self.repo))
        git_ops.configure_git_identity("Second", "second@x.com", repo_path=str(self.repo))
        self.assertEqual(_git(self.repo, "config", "--get", "user.name"), "Second")


class CommitWithDateTests(GitOpsTestBase):
    def test_backdates_author_and_committer(self):
        ts = 1700000000
        self._write("solution.py", "print('hi')")
        git_ops.commit_with_date("solve(0001): two sum", ts, repo_path=str(self.repo))

        self.assertEqual(_git(self.repo, "log", "-1", "--format=%at"), str(ts))
        self.assertEqual(_git(self.repo, "log", "-1", "--format=%ct"), str(ts))
        self.assertEqual(
            _git(self.repo, "log", "-1", "--format=%s"), "solve(0001): two sum"
        )

    def test_accepts_string_timestamp(self):
        ts = "1699999999"
        self._write("solution.py")
        git_ops.commit_with_date("solve(0002): add", ts, repo_path=str(self.repo))
        self.assertEqual(_git(self.repo, "log", "-1", "--format=%at"), ts)

    def test_stages_all_new_files(self):
        self._write("solution.py")
        self._write("metadata.json")
        self._write("README.md")
        git_ops.commit_with_date("solve(0003): files", 1700000000, repo_path=str(self.repo))

        tracked = set(_git(self.repo, "ls-tree", "-r", "HEAD", "--name-only").splitlines())
        self.assertEqual(tracked, {"solution.py", "metadata.json", "README.md"})

    def test_each_commit_keeps_its_own_date(self):
        self._write("a.py")
        git_ops.commit_with_date("first", 1700000000, repo_path=str(self.repo))
        self._write("b.py")
        git_ops.commit_with_date("second", 1700100000, repo_path=str(self.repo))

        dates = _git(self.repo, "log", "--format=%at").splitlines()
        self.assertEqual(dates, ["1700100000", "1700000000"])

    def test_raises_when_nothing_to_commit(self):
        with self.assertRaises(git_ops.GitError):
            git_ops.commit_with_date("empty", 1700000000, repo_path=str(self.repo))


class HasUncommittedChangesTests(GitOpsTestBase):
    def test_false_on_clean_tree(self):
        self._write("a.py")
        git_ops.commit_with_date("first", 1700000000, repo_path=str(self.repo))
        self.assertFalse(git_ops.has_uncommitted_changes(repo_path=str(self.repo)))

    def test_true_with_untracked_file(self):
        self._write("a.py")
        self.assertTrue(git_ops.has_uncommitted_changes(repo_path=str(self.repo)))

    def test_true_with_modified_tracked_file(self):
        self._write("a.py", "one")
        git_ops.commit_with_date("first", 1700000000, repo_path=str(self.repo))
        self._write("a.py", "two")
        self.assertTrue(git_ops.has_uncommitted_changes(repo_path=str(self.repo)))


class PushTests(GitOpsTestBase):
    def test_pushes_to_remote(self):
        remote = self._make_bare_remote()
        _git(self.repo, "remote", "add", "origin", str(remote))

        self._write("a.py")
        git_ops.commit_with_date("first", 1700000000, repo_path=str(self.repo))
        branch = _git(self.repo, "branch", "--show-current")
        _git(self.repo, "push", "-u", "origin", branch)

        self._write("b.py")
        git_ops.commit_with_date("second", 1700100000, repo_path=str(self.repo))
        git_ops.push(repo_path=str(self.repo))

        self.assertEqual(
            _git(self.repo, "rev-parse", "HEAD"),
            _git(remote, "rev-parse", branch),
        )

    def test_raises_without_configured_remote(self):
        self._write("a.py")
        git_ops.commit_with_date("first", 1700000000, repo_path=str(self.repo))
        with self.assertRaises(git_ops.GitError):
            git_ops.push(repo_path=str(self.repo))


if __name__ == "__main__":
    unittest.main()
