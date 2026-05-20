"""Claude integration for enriching LeetCode submissions.

One Claude call per submission. Returns a parsed dict with the keys
`problem_summary`, `approach`, `complexity`, `tags`, `commit_message`.

The system prompt lives in prompts/enrich.txt so it can be iterated on
without touching code. The path is overridable via LEETCODE_SYNC_PROMPT_PATH.

Per the plan: retry once with backoff on transient errors, then raise.
The caller is expected to log and skip the submission rather than crash
the whole run.
"""

from __future__ import annotations

import json
import logging
import os
import re
import time
from pathlib import Path
from typing import Any

import anthropic

DEFAULT_MODEL = os.environ.get("LEETCODE_SYNC_MODEL", "claude-sonnet-4-5")
DEFAULT_MAX_TOKENS = 2000
DEFAULT_PROMPT_PATH = Path("prompts/enrich.txt")
RETRY_BACKOFF_SECONDS = 2.0

log = logging.getLogger(__name__)


class AgentError(RuntimeError):
    """Base for ai_agent failures."""


class AgentParseError(AgentError):
    """Raised when the model response can't be parsed into the expected shape."""


_REQUIRED_KEYS = {
    "problem_summary",
    "approach",
    "complexity",
    "tags",
    "commit_message",
}

_JSON_FENCE_RE = re.compile(r"```(?:json)?\s*(\{.*\})\s*```", re.DOTALL)


def load_system_prompt() -> str:
    path = Path(os.environ.get("LEETCODE_SYNC_PROMPT_PATH", str(DEFAULT_PROMPT_PATH)))
    return path.read_text(encoding="utf-8")


def _build_user_content(submission: dict[str, Any]) -> str:
    question = submission.get("question") or {}
    lang = submission.get("lang") or {}
    lang_name = lang.get("name", "")
    lang_label = lang.get("verboseName") or lang_name
    return (
        "PROBLEM\n"
        f"Title: {question.get('title', '')}\n"
        f"Question ID: {question.get('questionId', '')}\n"
        f"Difficulty: {question.get('difficulty', '')}\n"
        "Statement (HTML):\n"
        f"{question.get('content', '')}\n\n"
        "SUBMISSION\n"
        f"Language: {lang_label}\n"
        f"Runtime: {submission.get('runtimeDisplay', '')}\n"
        f"Memory: {submission.get('memoryDisplay', '')}\n\n"
        "CODE\n"
        f"```{lang_name}\n"
        f"{submission.get('code', '')}\n"
        "```\n"
    )


def _parse_response(text: str) -> dict[str, Any]:
    text = text.strip()
    try:
        return json.loads(text)
    except json.JSONDecodeError:
        pass
    m = _JSON_FENCE_RE.search(text)
    if m:
        try:
            return json.loads(m.group(1))
        except json.JSONDecodeError as e:
            raise AgentParseError(f"Fenced JSON did not parse: {e}") from e
    raise AgentParseError("Response was not valid JSON")


def _validate_shape(obj: Any) -> None:
    if not isinstance(obj, dict):
        raise AgentParseError(f"Expected JSON object, got {type(obj).__name__}")
    missing = _REQUIRED_KEYS - obj.keys()
    if missing:
        raise AgentParseError(f"Missing required keys: {sorted(missing)}")
    complexity = obj["complexity"]
    if not isinstance(complexity, dict) or {"time", "space"} - complexity.keys():
        raise AgentParseError("complexity must be an object with 'time' and 'space'")
    if not isinstance(obj["tags"], list):
        raise AgentParseError("tags must be a list")
    if not isinstance(obj["commit_message"], str) or not obj["commit_message"].strip():
        raise AgentParseError("commit_message must be a non-empty string")


def _is_retryable(e: BaseException) -> bool:
    if isinstance(e, anthropic.APIConnectionError):
        return True
    if isinstance(e, anthropic.APIStatusError):
        status = getattr(e, "status_code", None)
        if status is None:
            return False
        return status >= 500 or status == 429
    return False


def enrich_submission(
    submission_details: dict[str, Any],
    *,
    client: anthropic.Anthropic | None = None,
    model: str | None = None,
) -> dict[str, Any]:
    """Call Claude to enrich one submission.

    Returns the parsed JSON dict. Retries once with backoff on transient
    errors (5xx, 429, connection errors). Raises AgentError on permanent
    failure or unparseable response.
    """
    client = client or anthropic.Anthropic()
    model = model or DEFAULT_MODEL
    system_prompt = load_system_prompt()
    user_content = _build_user_content(submission_details)

    message = _call_with_retry(client, model, system_prompt, user_content)

    text_parts = [b.text for b in message.content if getattr(b, "type", None) == "text"]
    if not text_parts:
        raise AgentParseError("Response had no text content")
    raw = "".join(text_parts)

    try:
        parsed = _parse_response(raw)
        _validate_shape(parsed)
    except AgentParseError:
        log.warning("Failed to parse agent response. Raw text:\n%s", raw)
        raise
    return parsed


def _call_with_retry(
    client: anthropic.Anthropic,
    model: str,
    system_prompt: str,
    user_content: str,
) -> anthropic.types.Message:
    last_error: BaseException | None = None
    for attempt in range(2):
        try:
            return client.messages.create(
                model=model,
                max_tokens=DEFAULT_MAX_TOKENS,
                system=[
                    {
                        "type": "text",
                        "text": system_prompt,
                        "cache_control": {"type": "ephemeral"},
                    }
                ],
                messages=[{"role": "user", "content": user_content}],
            )
        except Exception as e:
            last_error = e
            if attempt == 0 and _is_retryable(e):
                log.warning(
                    "Anthropic call failed (attempt 1/2): %s. Retrying in %.1fs",
                    e,
                    RETRY_BACKOFF_SECONDS,
                )
                time.sleep(RETRY_BACKOFF_SECONDS)
                continue
            raise AgentError(f"Anthropic API failed: {e}") from e
    raise AgentError(f"Anthropic API failed after retry: {last_error}")