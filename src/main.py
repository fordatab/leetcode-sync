"""Orchestrator entry point for the LeetCode -> GitHub sync.

Run with `python -m src.main`. Each run:

  1. Loads state.json.
  2. Fetches recent accepted submissions from LeetCode.
  3. Keeps only ones not already synced, oldest first.
  4. For each: fetches details, enriches via Claude, writes the problem
     folder, and commits backdated to the submission timestamp.
  5. Commits state.json with a normal (current-time) commit and pushes.

A single bad submission is logged and skipped so it never blocks the rest of
the run, but any failure makes the process exit non-zero (exit code 1) after
the successful submissions are committed and pushed — so a broken run shows up
red in CI instead of silently reporting success.

An expired LeetCode cookie aborts with a clear message (exit code 2). When
every submission-detail fetch returns null while the public recent list still
works — the signature of an expired session — that is treated as cookie
expiry too, since LeetCode nulls the field instead of returning 401.
"""

from __future__ import annotations

import argparse
import json
import logging
import sys
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from src import ai_agent, git_ops, leetcode, state

log = logging.getLogger(__name__)

DEFAULT_FETCH_LIMIT = 20
PROBLEMS_DIRNAME = "problems"


class SyncIncompleteError(RuntimeError):
    """Raised when one or more submissions failed to sync.

    Successful submissions are still committed and pushed before this is
    raised — it exists so the process exits non-zero (turning the CI run red)
    rather than reporting success while silently skipping work.
    """

# LeetCode `lang.name` slug -> source file extension.
_LANG_EXT = {
    "python": "py",
    "python3": "py",
    "pythondata": "py",
    "c": "c",
    "cpp": "cpp",
    "csharp": "cs",
    "java": "java",
    "kotlin": "kt",
    "scala": "scala",
    "javascript": "js",
    "typescript": "ts",
    "golang": "go",
    "rust": "rs",
    "swift": "swift",
    "ruby": "rb",
    "php": "php",
    "dart": "dart",
    "racket": "rkt",
    "erlang": "erl",
    "elixir": "ex",
    "bash": "sh",
    "mysql": "sql",
    "mssql": "sql",
    "oraclesql": "sql",
    "postgresql": "sql",
}


def _ext_for_lang(lang_name: str) -> str:
    name = (lang_name or "").lower()
    return _LANG_EXT.get(name, name or "txt")


def _folder_name(question: dict[str, Any]) -> str:
    """`<4-digit-id>-<title-slug>`, e.g. 0146-lru-cache."""
    padded = str(question.get("questionId", "0")).zfill(4)
    slug = question.get("titleSlug") or "unknown"
    return f"{padded}-{slug}"


def _render_readme(
    details: dict[str, Any], enrichment: dict[str, Any], timestamp: int
) -> str:
    question = details.get("question") or {}
    lang = details.get("lang") or {}
    complexity = enrichment.get("complexity") or {}
    tags = enrichment.get("tags") or []
    submitted = datetime.fromtimestamp(timestamp, tz=timezone.utc).strftime(
        "%Y-%m-%d %H:%M UTC"
    )
    return (
        f"# {question.get('title', '')}\n\n"
        f"**Difficulty:** {question.get('difficulty', '')}\n"
        f"**Tags:** {', '.join(tags)}\n\n"
        f"## Problem\n\n{enrichment.get('problem_summary', '')}\n\n"
        f"## Approach\n\n{enrichment.get('approach', '')}\n\n"
        f"## Complexity\n\n"
        f"- **Time:** {complexity.get('time', '')}\n"
        f"- **Space:** {complexity.get('space', '')}\n\n"
        f"## Stats\n\n"
        f"- Submitted: {submitted}\n"
        f"- Runtime: {details.get('runtimeDisplay', '')}\n"
        f"- Memory: {details.get('memoryDisplay', '')}\n"
        f"- Language: {lang.get('verboseName') or lang.get('name', '')}\n"
    )


def _append_metadata(
    path: Path, details: dict[str, Any], submission_id: int, timestamp: int
) -> None:
    """Append this submission's metadata to metadata.json, kept as a list.

    Solving the same problem in another language adds an entry rather than
    overwriting the old one.
    """
    lang = details.get("lang") or {}
    question = details.get("question") or {}
    entry = {
        "submission_id": submission_id,
        "timestamp": timestamp,
        "runtime": details.get("runtimeDisplay"),
        "memory": details.get("memoryDisplay"),
        "language": lang.get("verboseName") or lang.get("name"),
        "difficulty": question.get("difficulty"),
    }

    entries: list[dict[str, Any]] = []
    if path.exists():
        try:
            loaded = json.loads(path.read_text(encoding="utf-8"))
            entries = loaded if isinstance(loaded, list) else [loaded]
        except json.JSONDecodeError:
            log.warning("metadata.json at %s was unreadable; recreating it", path)

    if not any(e.get("submission_id") == submission_id for e in entries):
        entries.append(entry)
    path.write_text(json.dumps(entries, indent=2) + "\n", encoding="utf-8")


def _sync_one(submission: dict[str, Any], repo_path: str) -> bool:
    """Sync a single submission. Returns True if a commit was created.

    Every accepted submission produces its own backdated commit so the
    contribution graph reflects every accept, not just the first per problem.
    Resubmissions skip the Claude call and reuse the existing README — the
    metadata.json append always provides a non-empty diff, and the code
    overwrite captures any refactoring between resubmissions.
    """
    submission_id = int(submission["id"])
    timestamp = int(submission["timestamp"])

    details = leetcode.fetch_submission_details(submission_id)
    question = details.get("question") or {}
    lang = details.get("lang") or {}
    ext = _ext_for_lang(lang.get("name", ""))

    folder = Path(repo_path) / PROBLEMS_DIRNAME / _folder_name(question)
    solution_path = folder / f"solution.{ext}"
    is_resubmission = solution_path.exists()

    # Call Claude (if needed) before writing any files so a failure does not
    # leave a half-built folder on disk for the next run to trip over.
    enrichment = None
    if is_resubmission:
        padded = str(question.get("questionId", "0")).zfill(4)
        slug = question.get("titleSlug") or "unknown"
        commit_message = f"resubmit({padded}): {slug}"
    else:
        enrichment = ai_agent.enrich_submission(details)
        commit_message = enrichment["commit_message"]

    folder.mkdir(parents=True, exist_ok=True)
    solution_path.write_text(details.get("code") or "", encoding="utf-8")
    _append_metadata(folder / "metadata.json", details, submission_id, timestamp)
    if enrichment is not None:
        (folder / "README.md").write_text(
            _render_readme(details, enrichment, timestamp), encoding="utf-8"
        )

    git_ops.commit_with_date(commit_message, timestamp, repo_path)
    state.mark_synced(submission_id)
    log.info("Synced submission %s -> %s", submission_id, folder.name)
    return True


def run(
    limit: int = DEFAULT_FETCH_LIMIT,
    repo_path: str = ".",
    backfill: bool = False,
) -> int:
    """Run one full sync. Returns the number of problems committed.

    With backfill=True, paginates every accepted submission instead of just
    the most recent N. Intended for one-time historical import; for normal
    cron runs leave it False.

    Raises CookieExpiredError if LeetCode auth fails (caller should abort).
    Raises SyncIncompleteError if any individual submission failed to sync,
    after committing and pushing whatever succeeded.
    """
    current = state.load_state()
    synced_ids = {int(x) for x in current["synced_submission_ids"]}

    if backfill:
        fetched = leetcode.fetch_all_ac_submissions()
        label = "accepted"
    else:
        fetched = leetcode.fetch_recent_submissions(limit)
        label = "recent"
    new_subs = [s for s in fetched if int(s["id"]) not in synced_ids]
    new_subs.sort(key=lambda s: int(s["timestamp"]))
    log.info("%d %s submission(s), %d new to sync", len(fetched), label, len(new_subs))

    committed = 0
    failed = 0
    unavailable = 0  # subset of failed: submissionDetails came back null
    for submission in new_subs:
        submission_id = submission.get("id")
        try:
            if _sync_one(submission, repo_path):
                committed += 1
        except leetcode.CookieExpiredError:
            raise  # auth is dead — every later fetch fails too, so abort.
        except Exception as e:  # noqa: BLE001 - one bad submission must not block the rest
            failed += 1
            if isinstance(e, leetcode.SubmissionUnavailableError):
                unavailable += 1
            log.error(
                "Failed to sync submission %s (%s): %s",
                submission_id,
                submission.get("title"),
                e,
            )

    total_commits = committed
    if git_ops.has_uncommitted_changes(repo_path):
        git_ops.commit_with_date(
            "chore: update sync state", int(time.time()), repo_path
        )
        total_commits += 1

    if total_commits > 0:
        git_ops.push(repo_path)
        log.info("Done: %d problem(s) synced and pushed.", committed)
    elif not new_subs:
        log.info("Done: nothing new to sync.")

    if failed:
        # Every detail fetch returning null while the public recent-submissions
        # list succeeded is the signature of an expired session cookie, so point
        # at the real, manually-fixable cause instead of a generic failure.
        if new_subs and unavailable == len(new_subs):
            raise leetcode.CookieExpiredError(
                f"All {unavailable} submission detail fetch(es) returned null while "
                "the (public) recent-submissions list succeeded. submissionDetails "
                "requires authentication, so LEETCODE_SESSION is almost certainly "
                "expired or invalid — refresh it."
            )
        raise SyncIncompleteError(
            f"{failed} of {len(new_subs)} submission(s) failed to sync "
            f"({committed} succeeded). See the errors above."
        )
    return committed


def main(argv: list[str] | None = None) -> int:
    try:
        from dotenv import load_dotenv

        load_dotenv()
    except ImportError:
        pass

    parser = argparse.ArgumentParser(
        description="Sync recent LeetCode submissions into this repo."
    )
    parser.add_argument(
        "--limit",
        type=int,
        default=DEFAULT_FETCH_LIMIT,
        help="How many recent submissions to scan (default 20).",
    )
    parser.add_argument(
        "--repo-path",
        default=".",
        help="Path to the git repo to commit into (default: current dir).",
    )
    parser.add_argument(
        "--backfill",
        action="store_true",
        help="One-time historical import: paginate every accepted submission "
        "instead of just the recent ones. Ignores --limit.",
    )
    args = parser.parse_args(argv)

    logging.basicConfig(
        level=logging.INFO, format="%(levelname)s %(name)s: %(message)s"
    )

    try:
        run(limit=args.limit, repo_path=args.repo_path, backfill=args.backfill)
    except leetcode.CookieExpiredError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        print(
            "Cookie expired — refresh the LEETCODE_SESSION secret.", file=sys.stderr
        )
        return 2
    except SyncIncompleteError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        return 1
    except (leetcode.LeetCodeError, state.StateError, git_ops.GitError) as e:
        print(f"ERROR: {e}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
