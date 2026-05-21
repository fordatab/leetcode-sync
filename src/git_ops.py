"""Git operations for the LeetCode sync.

The defining requirement: each problem's commit is *backdated* to the
LeetCode submission timestamp so the GitHub contribution graph reflects
when the problem was actually solved, not when the sync job ran.

Three public functions:
    configure_git_identity(name, email, repo_path=".")
    commit_with_date(message, unix_timestamp, repo_path=".")
    push(repo_path=".")

All git invocations go through subprocess (no GitPython, per the plan).
A non-zero git exit raises GitError with the captured output.
"""

from __future__ import annotations

import logging
import os
import subprocess
from datetime import datetime, timezone

log = logging.getLogger(__name__)


class GitError(RuntimeError):
    """Raised when a git subprocess exits non-zero."""


def _run_git(
    args: list[str],
    *,
    repo_path: str = ".",
    env: dict[str, str] | None = None,
) -> subprocess.CompletedProcess[str]:
    result = subprocess.run(
        ["git", "-C", repo_path, *args],
        env=env,
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
    )
    if result.returncode != 0:
        detail = result.stderr.strip() or result.stdout.strip() or "(no output)"
        raise GitError(
            f"git {' '.join(args)} failed (exit {result.returncode}): {detail}"
        )
    return result


def configure_git_identity(name: str, email: str, repo_path: str = ".") -> None:
    """Set the local user.name / user.email used to author commits.

    For the GitHub contribution graph to credit the account, `email` must
    match a verified email on that GitHub account.
    """
    _run_git(["config", "user.name", name], repo_path=repo_path)
    _run_git(["config", "user.email", email], repo_path=repo_path)


def commit_with_date(
    message: str,
    unix_timestamp: int | str,
    repo_path: str = ".",
) -> None:
    """Stage everything and commit, backdated to `unix_timestamp`.

    Both the author and committer dates are set to the submission time so
    GitHub renders the commit on the correct day of the contribution graph.
    LeetCode returns timestamps as strings, so a str is accepted too.
    """
    iso = datetime.fromtimestamp(int(unix_timestamp), tz=timezone.utc).isoformat()
    env = os.environ.copy()
    env["GIT_AUTHOR_DATE"] = iso
    env["GIT_COMMITTER_DATE"] = iso
    _run_git(["add", "-A"], repo_path=repo_path)
    _run_git(["commit", "-m", message], repo_path=repo_path, env=env)
    log.info("Committed %r backdated to %s", message, iso)


def has_uncommitted_changes(repo_path: str = ".") -> bool:
    """True if the working tree has staged or unstaged changes (incl. untracked)."""
    result = _run_git(["status", "--porcelain"], repo_path=repo_path)
    return bool(result.stdout.strip())


def push(repo_path: str = ".") -> None:
    """Push the current branch to its configured upstream (origin)."""
    _run_git(["push"], repo_path=repo_path)
    log.info("Pushed to origin")
