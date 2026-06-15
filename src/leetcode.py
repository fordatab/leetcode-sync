"""LeetCode GraphQL client.

Two public functions:
    fetch_recent_submissions(limit=20) -> list[dict]
    fetch_submission_details(submission_id: int) -> dict

Credentials are read from environment variables on each call:
    LEETCODE_SESSION, LEETCODE_CSRF_TOKEN, LEETCODE_USERNAME
"""

from __future__ import annotations

import argparse
import json
import logging
import os
import sys
import time
from typing import Any

import requests

GRAPHQL_URL = "https://leetcode.com/graphql/"
DEFAULT_TIMEOUT = 30
BACKFILL_PAGE_SIZE = 20
BACKFILL_PAGE_DELAY_SEC = 0.25

log = logging.getLogger(__name__)

_RECENT_AC_QUERY = """
query recentAcSubmissions($username: String!, $limit: Int!) {
  recentAcSubmissionList(username: $username, limit: $limit) {
    id
    title
    titleSlug
    timestamp
  }
}
""".strip()

_ALL_SUBMISSIONS_QUERY = """
query submissionList($offset: Int!, $limit: Int!, $lastKey: String) {
  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey) {
    lastKey
    hasNext
    submissions {
      id
      title
      titleSlug
      timestamp
      statusDisplay
    }
  }
}
""".strip()

_SUBMISSION_DETAILS_QUERY = """
query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    runtime
    runtimeDisplay
    memory
    memoryDisplay
    code
    lang { name verboseName }
    question {
      questionId
      title
      titleSlug
      difficulty
      content
    }
    timestamp
  }
}
""".strip()


class LeetCodeError(RuntimeError):
    """Base error for LeetCode client failures."""


class CookieExpiredError(LeetCodeError):
    """Raised on 401/403 — the user must refresh LEETCODE_SESSION."""


class GraphQLError(LeetCodeError):
    """Raised when the GraphQL response contains an `errors` array."""


class SubmissionUnavailableError(LeetCodeError):
    """Raised when `submissionDetails` comes back null.

    LeetCode returns HTTP 200 with `submissionDetails: null` (no `errors`
    array) when the session cookie can't authorize access to the submission,
    instead of a 401/403. When *every* detail fetch in a run hits this while
    the public recent-submissions list still succeeds, an expired
    LEETCODE_SESSION is the overwhelmingly likely cause.
    """


def _require_env(name: str) -> str:
    value = os.environ.get(name)
    if not value:
        raise LeetCodeError(
            f"Missing required environment variable: {name}. "
            f"Set it in .env or as a GitHub Actions secret."
        )
    return value


def _post_graphql(
    query: str,
    variables: dict[str, Any],
    *,
    debug: bool = False,
) -> dict[str, Any]:
    session_cookie = _require_env("LEETCODE_SESSION")
    csrf_token = _require_env("LEETCODE_CSRF_TOKEN")

    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com/",
        "x-csrftoken": csrf_token,
        "User-Agent": "leetcode-sync/0.1 (+https://github.com)",
    }
    cookies = {
        "LEETCODE_SESSION": session_cookie,
        "csrftoken": csrf_token,
    }

    resp = requests.post(
        GRAPHQL_URL,
        json={"query": query, "variables": variables},
        headers=headers,
        cookies=cookies,
        timeout=DEFAULT_TIMEOUT,
    )

    if resp.status_code in (401, 403):
        raise CookieExpiredError(
            "LeetCode returned "
            f"{resp.status_code}. Cookie expired — refresh LEETCODE_SESSION "
            "and LEETCODE_CSRF_TOKEN from your browser."
        )

    if debug:
        log.warning("LeetCode raw response (status=%s): %s", resp.status_code, resp.text)

    resp.raise_for_status()

    try:
        payload = resp.json()
    except ValueError as e:
        raise LeetCodeError(
            f"LeetCode returned non-JSON response (status={resp.status_code}): "
            f"{resp.text[:500]}"
        ) from e

    if payload.get("errors"):
        raise GraphQLError(
            f"GraphQL errors: {json.dumps(payload['errors'])}. "
            f"Full payload: {json.dumps(payload)[:1000]}"
        )

    data = payload.get("data")
    if data is None:
        raise LeetCodeError(
            f"GraphQL response missing 'data' field. Full payload: {json.dumps(payload)[:500]}"
        )
    return data


def fetch_recent_submissions(limit: int = 20, *, debug: bool = False) -> list[dict[str, Any]]:
    """Return recent accepted submissions for LEETCODE_USERNAME.

    Each dict has keys: id (str), title, titleSlug, timestamp (str unix seconds).
    """
    username = _require_env("LEETCODE_USERNAME")
    data = _post_graphql(
        _RECENT_AC_QUERY,
        {"username": username, "limit": limit},
        debug=debug,
    )
    submissions = data.get("recentAcSubmissionList")
    if submissions is None:
        raise LeetCodeError(
            "recentAcSubmissionList was null — username may be invalid or cookies "
            f"unauthorized. Data: {json.dumps(data)[:500]}"
        )
    return submissions


def fetch_all_ac_submissions(*, debug: bool = False) -> list[dict[str, Any]]:
    """Return every accepted submission for the current user, oldest first.

    Pages through `submissionList` with offset+lastKey until exhausted, then
    filters to `statusDisplay == "Accepted"`. Shape per entry matches
    `fetch_recent_submissions` so downstream code is unchanged.
    """
    out: list[dict[str, Any]] = []
    seen_ids: set[str] = set()
    offset = 0
    last_key: str | None = None

    while True:
        data = _post_graphql(
            _ALL_SUBMISSIONS_QUERY,
            {"offset": offset, "limit": BACKFILL_PAGE_SIZE, "lastKey": last_key},
            debug=debug,
        )
        page = data.get("submissionList")
        if page is None:
            raise LeetCodeError(
                "submissionList was null — schema may have drifted or cookies "
                f"are unauthorized. Data: {json.dumps(data)[:500]}"
            )

        submissions = page.get("submissions") or []
        for s in submissions:
            sid = str(s.get("id"))
            if sid in seen_ids:
                continue
            seen_ids.add(sid)
            if s.get("statusDisplay") != "Accepted":
                continue
            out.append(
                {
                    "id": sid,
                    "title": s.get("title"),
                    "titleSlug": s.get("titleSlug"),
                    "timestamp": str(s.get("timestamp")),
                }
            )

        if not page.get("hasNext"):
            break
        offset += BACKFILL_PAGE_SIZE
        last_key = page.get("lastKey")
        time.sleep(BACKFILL_PAGE_DELAY_SEC)

    out.sort(key=lambda x: int(x["timestamp"]))
    return out


def fetch_submission_details(submission_id: int, *, debug: bool = False) -> dict[str, Any]:
    """Return full details for a single submission ID."""
    data = _post_graphql(
        _SUBMISSION_DETAILS_QUERY,
        {"submissionId": int(submission_id)},
        debug=debug,
    )
    details = data.get("submissionDetails")
    if details is None:
        raise SubmissionUnavailableError(
            f"submissionDetails was null for id={submission_id} — the session "
            "cookie may be expired/unauthorized (LeetCode nulls this field instead "
            "of returning 401), the id may not belong to this account, or the "
            f"schema has drifted. Data: {json.dumps(data)[:500]}"
        )
    return details


def _main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="LeetCode GraphQL client debug CLI")
    parser.add_argument(
        "--debug-query",
        action="store_true",
        help="Log full raw responses to stderr",
    )
    sub = parser.add_subparsers(dest="cmd", required=True)

    p_recent = sub.add_parser("recent", help="Fetch recent accepted submissions")
    p_recent.add_argument("--limit", type=int, default=20)

    p_details = sub.add_parser("details", help="Fetch details for a submission id")
    p_details.add_argument("submission_id", type=int)

    sub.add_parser("backfill", help="Paginate every accepted submission (oldest first)")

    args = parser.parse_args(argv)

    logging.basicConfig(level=logging.WARNING, format="%(levelname)s %(name)s: %(message)s")

    try:
        if args.cmd == "recent":
            result = fetch_recent_submissions(args.limit, debug=args.debug_query)
        elif args.cmd == "backfill":
            result = fetch_all_ac_submissions(debug=args.debug_query)
        else:
            result = fetch_submission_details(args.submission_id, debug=args.debug_query)
    except CookieExpiredError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        return 2
    except LeetCodeError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        return 1

    print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(_main())