"""Unit tests for src.leetcode.

All tests mock requests.post so no real network calls happen.
"""

from __future__ import annotations

import json
import unittest
from unittest import mock

from src import leetcode


def _fake_response(
    *,
    status_code: int = 200,
    json_body: dict | None = None,
    text: str | None = None,
):
    """Build a stand-in for requests.Response with just the bits we use."""
    m = mock.Mock()
    m.status_code = status_code
    if json_body is not None:
        m.json.return_value = json_body
        m.text = json.dumps(json_body)
    else:
        m.json.side_effect = ValueError("no json")
        m.text = text or ""

    def _raise_for_status():
        if status_code >= 400:
            raise leetcode.requests.HTTPError(f"HTTP {status_code}")

    m.raise_for_status.side_effect = _raise_for_status
    return m


VALID_ENV = {
    "LEETCODE_SESSION": "sess",
    "LEETCODE_CSRF_TOKEN": "csrf",
    "LEETCODE_USERNAME": "alice",
}


class RequireEnvTests(unittest.TestCase):
    def test_missing_env_raises_leetcode_error(self):
        with mock.patch.dict(leetcode.os.environ, {}, clear=True):
            with self.assertRaises(leetcode.LeetCodeError) as ctx:
                leetcode.fetch_recent_submissions()
        self.assertIn("Missing required environment variable", str(ctx.exception))


class FetchRecentSubmissionsTests(unittest.TestCase):
    def test_happy_path_returns_list(self):
        payload = {
            "data": {
                "recentAcSubmissionList": [
                    {
                        "id": "111",
                        "title": "Two Sum",
                        "titleSlug": "two-sum",
                        "timestamp": "1700000000",
                    }
                ]
            }
        }
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(json_body=payload)
        ) as post:
            out = leetcode.fetch_recent_submissions(limit=5)

        self.assertEqual(out, payload["data"]["recentAcSubmissionList"])

        # Verify request shape: URL, headers, cookies, variables.
        args, kwargs = post.call_args
        self.assertEqual(args[0], leetcode.GRAPHQL_URL)
        self.assertEqual(kwargs["cookies"]["LEETCODE_SESSION"], "sess")
        self.assertEqual(kwargs["cookies"]["csrftoken"], "csrf")
        self.assertEqual(kwargs["headers"]["x-csrftoken"], "csrf")
        self.assertEqual(kwargs["headers"]["Referer"], "https://leetcode.com/")
        self.assertEqual(kwargs["headers"]["Content-Type"], "application/json")
        self.assertEqual(kwargs["json"]["variables"], {"username": "alice", "limit": 5})
        self.assertIn("recentAcSubmissionList", kwargs["json"]["query"])

    def test_401_raises_cookie_expired(self):
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(status_code=401, text="nope")
        ):
            with self.assertRaises(leetcode.CookieExpiredError):
                leetcode.fetch_recent_submissions()

    def test_403_raises_cookie_expired(self):
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(status_code=403, text="nope")
        ):
            with self.assertRaises(leetcode.CookieExpiredError):
                leetcode.fetch_recent_submissions()

    def test_graphql_errors_field_raises(self):
        payload = {"errors": [{"message": "boom"}], "data": None}
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(json_body=payload)
        ):
            with self.assertRaises(leetcode.GraphQLError) as ctx:
                leetcode.fetch_recent_submissions()
        self.assertIn("boom", str(ctx.exception))

    def test_null_submission_list_raises(self):
        payload = {"data": {"recentAcSubmissionList": None}}
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(json_body=payload)
        ):
            with self.assertRaises(leetcode.LeetCodeError):
                leetcode.fetch_recent_submissions()

    def test_non_json_response_raises(self):
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests,
            "post",
            return_value=_fake_response(status_code=200, text="<html>down</html>"),
        ):
            with self.assertRaises(leetcode.LeetCodeError):
                leetcode.fetch_recent_submissions()

    def test_debug_logs_raw_response(self):
        payload = {"data": {"recentAcSubmissionList": []}}
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(json_body=payload)
        ), self.assertLogs(leetcode.log, level="WARNING") as captured:
            leetcode.fetch_recent_submissions(debug=True)
        self.assertTrue(any("raw response" in line for line in captured.output))


class FetchSubmissionDetailsTests(unittest.TestCase):
    def test_happy_path(self):
        details = {
            "code": "print(1)",
            "lang": {"name": "python3", "verboseName": "Python3"},
            "question": {
                "questionId": "1",
                "title": "Two Sum",
                "titleSlug": "two-sum",
                "difficulty": "Easy",
                "content": "<p>...</p>",
            },
            "timestamp": "1700000000",
            "runtime": "50",
            "runtimeDisplay": "50 ms",
            "memory": "14000000",
            "memoryDisplay": "14 MB",
        }
        payload = {"data": {"submissionDetails": details}}
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(json_body=payload)
        ) as post:
            out = leetcode.fetch_submission_details(123)
        self.assertEqual(out, details)
        _, kwargs = post.call_args
        self.assertEqual(kwargs["json"]["variables"], {"submissionId": 123})

    def test_null_details_raises(self):
        payload = {"data": {"submissionDetails": None}}
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(json_body=payload)
        ):
            with self.assertRaises(leetcode.LeetCodeError):
                leetcode.fetch_submission_details(999)


class CLITests(unittest.TestCase):
    def test_cookie_expired_exit_code_2(self):
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(status_code=401, text="x")
        ):
            rc = leetcode._main(["recent", "--limit", "1"])
        self.assertEqual(rc, 2)

    def test_recent_success_exit_code_0(self):
        payload = {"data": {"recentAcSubmissionList": []}}
        with mock.patch.dict(leetcode.os.environ, VALID_ENV, clear=True), mock.patch.object(
            leetcode.requests, "post", return_value=_fake_response(json_body=payload)
        ):
            rc = leetcode._main(["recent"])
        self.assertEqual(rc, 0)


if __name__ == "__main__":
    unittest.main()