"""Structural checks for the GitHub Actions workflow.

A workflow file cannot be executed here, so these tests validate that the
YAML parses and wires up the triggers, permissions, secrets and commands
the sync depends on. Requires PyYAML (see requirements-dev.txt).
"""

from __future__ import annotations

import unittest
from pathlib import Path

import yaml

WORKFLOW_PATH = (
    Path(__file__).resolve().parents[1] / ".github" / "workflows" / "sync.yml"
)


class WorkflowFileTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.doc = yaml.safe_load(WORKFLOW_PATH.read_text(encoding="utf-8"))

    def test_file_exists(self):
        self.assertTrue(WORKFLOW_PATH.is_file())

    def test_parses_as_yaml_mapping(self):
        self.assertIsInstance(self.doc, dict)

    def _triggers(self):
        # PyYAML follows YAML 1.1, where the bare key `on` parses as the
        # boolean True — so a workflow's triggers live under either key.
        return self.doc.get("on", self.doc.get(True))

    def _steps(self):
        return self.doc["jobs"]["sync"]["steps"]

    def _runs(self):
        return [str(s.get("run", "")) for s in self._steps()]

    def test_runs_on_six_hour_cron(self):
        crons = [s["cron"] for s in self._triggers()["schedule"]]
        self.assertIn("0 */6 * * *", crons)

    def test_supports_manual_dispatch(self):
        self.assertIn("workflow_dispatch", self._triggers())

    def test_grants_contents_write(self):
        self.assertEqual(self.doc["permissions"]["contents"], "write")

    def test_job_runs_on_ubuntu(self):
        self.assertEqual(self.doc["jobs"]["sync"]["runs-on"], "ubuntu-latest")

    def test_checks_out_with_full_history(self):
        checkout = next(
            s for s in self._steps()
            if str(s.get("uses", "")).startswith("actions/checkout")
        )
        self.assertEqual(checkout["with"]["fetch-depth"], 0)

    def test_sets_up_python(self):
        setup = next(
            s for s in self._steps()
            if str(s.get("uses", "")).startswith("actions/setup-python")
        )
        self.assertIn("python-version", setup["with"])

    def test_installs_requirements(self):
        self.assertTrue(
            any("pip install -r requirements.txt" in run for run in self._runs())
        )

    def test_runs_the_orchestrator(self):
        self.assertTrue(any("python -m src.main" in run for run in self._runs()))

    def test_configures_git_identity(self):
        self.assertTrue(any("git config user.name" in run for run in self._runs()))

    def test_pushes_at_the_end(self):
        self.assertTrue(any(run.strip() == "git push" for run in self._runs()))

    def test_run_step_passes_all_required_secrets(self):
        run_step = next(
            s for s in self._steps()
            if "python -m src.main" in str(s.get("run", ""))
        )
        env = run_step["env"]
        for var in (
            "LEETCODE_SESSION",
            "LEETCODE_CSRF_TOKEN",
            "LEETCODE_USERNAME",
            "ANTHROPIC_API_KEY",
        ):
            self.assertIn(var, env)
            self.assertIn(f"secrets.{var}", env[var])


if __name__ == "__main__":
    unittest.main()
