"""Unit tests for src.state.

Uses LEETCODE_SYNC_STATE_PATH to point each test at a fresh tmp file.
"""

from __future__ import annotations

import json
import os
import re
import tempfile
import unittest
from pathlib import Path
from unittest import mock

from src import state


class StateTestBase(unittest.TestCase):
    def setUp(self):
        self.tmpdir = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmpdir.cleanup)
        self.state_path = Path(self.tmpdir.name) / "state.json"
        self._env_patch = mock.patch.dict(
            os.environ, {"LEETCODE_SYNC_STATE_PATH": str(self.state_path)}
        )
        self._env_patch.start()
        self.addCleanup(self._env_patch.stop)


class LoadStateTests(StateTestBase):
    def test_missing_file_returns_empty_state(self):
        s = state.load_state()
        self.assertEqual(s, {"last_run": None, "synced_submission_ids": []})
        self.assertFalse(self.state_path.exists())

    def test_round_trip(self):
        original = {"last_run": "2026-05-20T14:00:00Z", "synced_submission_ids": [1, 2, 3]}
        self.state_path.write_text(json.dumps(original), encoding="utf-8")
        loaded = state.load_state()
        self.assertEqual(loaded, original)

    def test_corrupt_json_raises(self):
        self.state_path.write_text("{not json", encoding="utf-8")
        with self.assertRaises(state.StateError):
            state.load_state()

    def test_non_dict_root_raises(self):
        self.state_path.write_text("[1, 2, 3]", encoding="utf-8")
        with self.assertRaises(state.StateError):
            state.load_state()

    def test_synced_ids_must_be_list(self):
        self.state_path.write_text(
            json.dumps({"synced_submission_ids": "oops"}), encoding="utf-8"
        )
        with self.assertRaises(state.StateError):
            state.load_state()

    def test_missing_fields_get_defaults(self):
        self.state_path.write_text("{}", encoding="utf-8")
        s = state.load_state()
        self.assertIsNone(s["last_run"])
        self.assertEqual(s["synced_submission_ids"], [])


class SaveStateTests(StateTestBase):
    def test_save_writes_pretty_json_with_trailing_newline(self):
        state.save_state({"last_run": "x", "synced_submission_ids": [9, 8]})
        text = self.state_path.read_text(encoding="utf-8")
        self.assertTrue(text.endswith("\n"))
        self.assertEqual(json.loads(text), {"last_run": "x", "synced_submission_ids": [9, 8]})

    def test_save_is_atomic_no_tmp_left_behind(self):
        state.save_state({"last_run": None, "synced_submission_ids": []})
        leftovers = list(self.state_path.parent.glob(".state-*"))
        self.assertEqual(leftovers, [])

    def test_save_overwrites(self):
        state.save_state({"last_run": "a", "synced_submission_ids": [1]})
        state.save_state({"last_run": "b", "synced_submission_ids": [2]})
        self.assertEqual(
            state.load_state(), {"last_run": "b", "synced_submission_ids": [2]}
        )


class IsSyncedTests(StateTestBase):
    def test_returns_false_when_file_missing(self):
        self.assertFalse(state.is_synced(123))

    def test_returns_true_for_recorded_id(self):
        self.state_path.write_text(
            json.dumps({"synced_submission_ids": [123, 456]}), encoding="utf-8"
        )
        self.assertTrue(state.is_synced(123))
        self.assertTrue(state.is_synced(456))
        self.assertFalse(state.is_synced(999))

    def test_int_string_equivalence(self):
        self.state_path.write_text(
            json.dumps({"synced_submission_ids": ["123"]}), encoding="utf-8"
        )
        self.assertTrue(state.is_synced(123))


class MarkSyncedTests(StateTestBase):
    def test_persists_new_id(self):
        state.mark_synced(42)
        s = state.load_state()
        self.assertEqual(s["synced_submission_ids"], [42])

    def test_appends_to_existing(self):
        state.mark_synced(1)
        state.mark_synced(2)
        state.mark_synced(3)
        self.assertEqual(state.load_state()["synced_submission_ids"], [1, 2, 3])

    def test_idempotent_no_duplicates(self):
        state.mark_synced(7)
        state.mark_synced(7)
        state.mark_synced(7)
        self.assertEqual(state.load_state()["synced_submission_ids"], [7])

    def test_updates_last_run_iso8601_utc(self):
        state.mark_synced(1)
        last_run = state.load_state()["last_run"]
        self.assertIsNotNone(last_run)
        self.assertRegex(last_run, r"^\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}Z$")


if __name__ == "__main__":
    unittest.main()