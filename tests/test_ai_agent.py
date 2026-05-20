"""Unit tests for src.ai_agent.

The anthropic client is mocked so no real API calls happen.
"""

from __future__ import annotations

import json
import os
import unittest
from unittest import mock

import anthropic

from src import ai_agent


SAMPLE_SUBMISSION = {
    "code": "def two_sum(nums, target):\n    return [0, 1]",
    "lang": {"name": "python3", "verboseName": "Python3"},
    "question": {
        "questionId": "1",
        "title": "Two Sum",
        "titleSlug": "two-sum",
        "difficulty": "Easy",
        "content": "<p>Given an array...</p>",
    },
    "timestamp": "1700000000",
    "runtimeDisplay": "52 ms",
    "memoryDisplay": "14.2 MB",
}


VALID_RESPONSE = {
    "problem_summary": "Find two indices in an array whose values sum to a target.",
    "approach": "Use a hash map of value -> index to find the complement in one pass.",
    "complexity": {"time": "O(n)", "space": "O(n)"},
    "tags": ["array", "hash-table"],
    "commit_message": "solve(0001): two sum via hashmap",
}


class _FakeAPIStatusError(anthropic.APIStatusError):
    """Raisable stand-in for anthropic.APIStatusError without needing a real httpx.Response."""

    def __init__(self, status_code: int):
        self.status_code = status_code
        Exception.__init__(self, f"HTTP {status_code}")


def _fake_text_block(text: str):
    block = mock.Mock()
    block.type = "text"
    block.text = text
    return block


def _fake_message(text: str):
    msg = mock.Mock(spec=anthropic.types.Message)
    msg.content = [_fake_text_block(text)]
    return msg


def _mock_client(side_effect):
    """Build an Anthropic stand-in. side_effect is passed to messages.create."""
    client = mock.Mock(spec=anthropic.Anthropic)
    client.messages = mock.Mock()
    if isinstance(side_effect, list):
        client.messages.create.side_effect = side_effect
    elif isinstance(side_effect, Exception):
        client.messages.create.side_effect = side_effect
    else:
        client.messages.create.return_value = side_effect
    return client


def _patch_prompt(text: str = "SYSTEM"):
    return mock.patch.object(ai_agent, "load_system_prompt", return_value=text)


class BuildUserContentTests(unittest.TestCase):
    def test_includes_title_code_language_stats(self):
        content = ai_agent._build_user_content(SAMPLE_SUBMISSION)
        self.assertIn("Two Sum", content)
        self.assertIn("Easy", content)
        self.assertIn("def two_sum", content)
        self.assertIn("Python3", content)
        self.assertIn("52 ms", content)
        self.assertIn("14.2 MB", content)


class ParseResponseTests(unittest.TestCase):
    def test_plain_json(self):
        result = ai_agent._parse_response(json.dumps(VALID_RESPONSE))
        self.assertEqual(result, VALID_RESPONSE)

    def test_fenced_json(self):
        text = "```json\n" + json.dumps(VALID_RESPONSE) + "\n```"
        result = ai_agent._parse_response(text)
        self.assertEqual(result, VALID_RESPONSE)

    def test_fenced_no_lang(self):
        text = "```\n" + json.dumps(VALID_RESPONSE) + "\n```"
        result = ai_agent._parse_response(text)
        self.assertEqual(result, VALID_RESPONSE)

    def test_garbage_raises(self):
        with self.assertRaises(ai_agent.AgentParseError):
            ai_agent._parse_response("not json at all")


class ValidateShapeTests(unittest.TestCase):
    def test_valid(self):
        ai_agent._validate_shape(VALID_RESPONSE)  # no raise

    def test_missing_key(self):
        bad = {k: v for k, v in VALID_RESPONSE.items() if k != "tags"}
        with self.assertRaises(ai_agent.AgentParseError) as ctx:
            ai_agent._validate_shape(bad)
        self.assertIn("tags", str(ctx.exception))

    def test_complexity_not_object(self):
        bad = {**VALID_RESPONSE, "complexity": "O(n)"}
        with self.assertRaises(ai_agent.AgentParseError):
            ai_agent._validate_shape(bad)

    def test_complexity_missing_subkey(self):
        bad = {**VALID_RESPONSE, "complexity": {"time": "O(n)"}}
        with self.assertRaises(ai_agent.AgentParseError):
            ai_agent._validate_shape(bad)

    def test_tags_not_list(self):
        bad = {**VALID_RESPONSE, "tags": "array,hash-table"}
        with self.assertRaises(ai_agent.AgentParseError):
            ai_agent._validate_shape(bad)

    def test_commit_message_empty(self):
        bad = {**VALID_RESPONSE, "commit_message": ""}
        with self.assertRaises(ai_agent.AgentParseError):
            ai_agent._validate_shape(bad)

    def test_non_dict_root(self):
        with self.assertRaises(ai_agent.AgentParseError):
            ai_agent._validate_shape([1, 2, 3])


class IsRetryableTests(unittest.TestCase):
    def test_connection_error_is_retryable(self):
        e = anthropic.APIConnectionError(request=mock.Mock())
        self.assertTrue(ai_agent._is_retryable(e))

    def test_500_is_retryable(self):
        e = _FakeAPIStatusError(500)
        self.assertTrue(ai_agent._is_retryable(e))

    def test_429_is_retryable(self):
        e = _FakeAPIStatusError(429)
        self.assertTrue(ai_agent._is_retryable(e))

    def test_400_is_not_retryable(self):
        e = _FakeAPIStatusError(400)
        self.assertFalse(ai_agent._is_retryable(e))

    def test_value_error_is_not_retryable(self):
        self.assertFalse(ai_agent._is_retryable(ValueError("nope")))


class EnrichSubmissionTests(unittest.TestCase):
    def test_happy_path(self):
        client = _mock_client(_fake_message(json.dumps(VALID_RESPONSE)))
        with _patch_prompt(), mock.patch.object(ai_agent.time, "sleep"):
            result = ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)

        self.assertEqual(result, VALID_RESPONSE)
        client.messages.create.assert_called_once()

        # Verify request shape.
        kwargs = client.messages.create.call_args.kwargs
        self.assertEqual(kwargs["model"], ai_agent.DEFAULT_MODEL)
        self.assertEqual(kwargs["max_tokens"], ai_agent.DEFAULT_MAX_TOKENS)
        self.assertEqual(kwargs["system"][0]["text"], "SYSTEM")
        self.assertEqual(kwargs["system"][0]["cache_control"], {"type": "ephemeral"})
        self.assertEqual(kwargs["messages"][0]["role"], "user")
        self.assertIn("Two Sum", kwargs["messages"][0]["content"])

    def test_model_override(self):
        client = _mock_client(_fake_message(json.dumps(VALID_RESPONSE)))
        with _patch_prompt():
            ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client, model="custom-model")
        self.assertEqual(client.messages.create.call_args.kwargs["model"], "custom-model")

    def test_retry_on_5xx_then_succeed(self):
        err = _FakeAPIStatusError(500)
        client = _mock_client([err, _fake_message(json.dumps(VALID_RESPONSE))])
        with _patch_prompt(), mock.patch.object(ai_agent.time, "sleep") as sleep:
            result = ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)
        self.assertEqual(result, VALID_RESPONSE)
        self.assertEqual(client.messages.create.call_count, 2)
        sleep.assert_called_once_with(ai_agent.RETRY_BACKOFF_SECONDS)

    def test_retry_on_429_then_succeed(self):
        err = _FakeAPIStatusError(429)
        client = _mock_client([err, _fake_message(json.dumps(VALID_RESPONSE))])
        with _patch_prompt(), mock.patch.object(ai_agent.time, "sleep"):
            result = ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)
        self.assertEqual(result, VALID_RESPONSE)

    def test_no_retry_on_400(self):
        err = _FakeAPIStatusError(400)
        client = _mock_client(err)
        with _patch_prompt(), mock.patch.object(ai_agent.time, "sleep") as sleep:
            with self.assertRaises(ai_agent.AgentError):
                ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)
        sleep.assert_not_called()
        self.assertEqual(client.messages.create.call_count, 1)

    def test_two_consecutive_5xx_raises(self):
        err = _FakeAPIStatusError(500)
        client = _mock_client([err, _FakeAPIStatusError(500)])
        with _patch_prompt(), mock.patch.object(ai_agent.time, "sleep"):
            with self.assertRaises(ai_agent.AgentError):
                ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)
        self.assertEqual(client.messages.create.call_count, 2)

    def test_parse_failure_logs_raw_text(self):
        client = _mock_client(_fake_message("not json"))
        with _patch_prompt(), self.assertLogs(ai_agent.log, level="WARNING") as cap:
            with self.assertRaises(ai_agent.AgentParseError):
                ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)
        self.assertTrue(any("not json" in line for line in cap.output))

    def test_validation_failure_logs_raw_text(self):
        bad = {**VALID_RESPONSE}
        del bad["tags"]
        client = _mock_client(_fake_message(json.dumps(bad)))
        with _patch_prompt(), self.assertLogs(ai_agent.log, level="WARNING") as cap:
            with self.assertRaises(ai_agent.AgentParseError) as ctx:
                ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)
        self.assertIn("tags", str(ctx.exception))
        self.assertTrue(any("Failed to parse" in line for line in cap.output))

    def test_no_text_blocks_raises(self):
        empty = mock.Mock(spec=anthropic.types.Message)
        empty.content = []
        client = _mock_client(empty)
        with _patch_prompt():
            with self.assertRaises(ai_agent.AgentParseError):
                ai_agent.enrich_submission(SAMPLE_SUBMISSION, client=client)


class LoadSystemPromptTests(unittest.TestCase):
    def test_env_override(self):
        with mock.patch.dict(
            os.environ,
            {"LEETCODE_SYNC_PROMPT_PATH": str(ai_agent.DEFAULT_PROMPT_PATH)},
        ):
            text = ai_agent.load_system_prompt()
        self.assertIn("JSON", text)


if __name__ == "__main__":
    unittest.main()