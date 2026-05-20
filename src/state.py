"""State management for the LeetCode sync.

state.json at the repo root tracks which submission IDs have already been
synced so reruns don't duplicate work. Shape:

    {
        "last_run": "2026-05-20T14:00:00Z",
        "synced_submission_ids": [1234567, 1234568]
    }

The file is committed to the repo so the next Actions run resumes cleanly.
Writes are atomic (write to a temp file then os.replace) so a crash mid-write
never leaves a half-written state.json.
"""

from __future__ import annotations

import json
import os
import tempfile
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

DEFAULT_STATE_PATH = Path("state.json")


class StateError(RuntimeError):
    """Raised when state.json is unreadable or malformed."""


def _empty_state() -> dict[str, Any]:
    return {"last_run": None, "synced_submission_ids": []}


def _state_path() -> Path:
    override = os.environ.get("LEETCODE_SYNC_STATE_PATH")
    return Path(override) if override else DEFAULT_STATE_PATH


def load_state() -> dict[str, Any]:
    """Read state.json. Returns an empty state if the file does not exist."""
    path = _state_path()
    if not path.exists():
        return _empty_state()
    try:
        with path.open("r", encoding="utf-8") as f:
            data = json.load(f)
    except json.JSONDecodeError as e:
        raise StateError(
            f"state.json is not valid JSON ({path}): {e}. "
            f"Fix or delete the file to start fresh."
        ) from e

    if not isinstance(data, dict):
        raise StateError(f"state.json must be a JSON object, got {type(data).__name__}")

    data.setdefault("last_run", None)
    ids = data.setdefault("synced_submission_ids", [])
    if not isinstance(ids, list):
        raise StateError("synced_submission_ids must be a list")
    return data


def save_state(state: dict[str, Any]) -> None:
    """Atomically write state to disk."""
    path = _state_path()
    path.parent.mkdir(parents=True, exist_ok=True)

    fd, tmp_path = tempfile.mkstemp(
        prefix=".state-", suffix=".json.tmp", dir=str(path.parent or ".")
    )
    try:
        with os.fdopen(fd, "w", encoding="utf-8") as f:
            json.dump(state, f, indent=2, sort_keys=True)
            f.write("\n")
        os.replace(tmp_path, path)
    except Exception:
        try:
            os.unlink(tmp_path)
        except OSError:
            pass
        raise


def is_synced(submission_id: int) -> bool:
    """True if this submission_id is already recorded in state.json."""
    state = load_state()
    return int(submission_id) in {int(x) for x in state["synced_submission_ids"]}


def mark_synced(submission_id: int) -> None:
    """Record submission_id as synced and update last_run. Idempotent."""
    state = load_state()
    sid = int(submission_id)
    ids = [int(x) for x in state["synced_submission_ids"]]
    if sid not in ids:
        ids.append(sid)
    state["synced_submission_ids"] = ids
    state["last_run"] = datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")
    save_state(state)