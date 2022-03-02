# Open items

Punch list of decisions, placeholders, and trade-offs flagged while building components 1, 2, 3, and 6 — things that are non-obvious from reading the code or PLAN.md alone.

> The authoritative copy lives at `C:\Users\ugcir\.claude\projects\C--Users-ugcir-Desktop-leetcode-sync\memory\open_items.md` so future Claude Code sessions load it automatically. This file is a readable mirror.

---

## Component 6 — workflow
- **Replace `YOUR_VERIFIED_GITHUB_EMAIL`** in `.github/workflows/sync.yml` `Configure git` step. Required for the contribution graph to credit commits.
- **Redundant push:** the workflow has a final `git push` step AND the plan's main.py step 7 also pushes. Pick one when component 5 lands — either remove the workflow step or remove `git_ops.push()` from the orchestrator. Both is harmless but confusing.
- **Add four secrets** in repo Settings → Secrets and variables → Actions: `LEETCODE_SESSION`, `LEETCODE_CSRF_TOKEN`, `LEETCODE_USERNAME`, `ANTHROPIC_API_KEY`. `GITHUB_TOKEN` is auto-provided.

## Component 3 — AI agent
- **Model is `claude-sonnet-4-5`** per the plan. This is a legacy model (still active). The claude-api skill recommends `claude-opus-4-7` as default. I followed the plan; user may want to bump to `claude-sonnet-4-6` or `claude-opus-4-7`. Overridable via `LEETCODE_SYNC_MODEL` env var — no code change needed.
- **Retry is single-attempt with 2s constant backoff**, not "exponential" as the plan word-says. With only one retry, exponential is meaningless; if the user wants a real exponential schedule, increase the retry count first.
- **Shape validation goes beyond the plan:** `complexity` must be a dict with `time`+`space`, `tags` must be a list, `commit_message` must be a non-empty string. Plan didn't require this — if the model returns valid-JSON-but-wrong-shape, we skip the submission rather than write garbage to disk.
- **Prompt caching marker is present but likely no-ops** — the current `prompts/enrich.txt` is under the 2048-token minimum for caching on Sonnet 4.5 / Sonnet 4.6. Will start working when the prompt grows. Costs nothing to leave in.

## Component 2 — state
- **Atomic writes via tmpfile + `os.replace`** — not required by the plan, added defensively against Actions-runner-killed-mid-write corrupting state.json. Keep when integrating into the orchestrator.
- **`LEETCODE_SYNC_STATE_PATH` env override** — added for testability. Default is `state.json` at the working dir, which is what the workflow expects.

## Component 1 — leetcode client
- **`--debug-query` CLI flag** wired up per the plan, but currently only the standalone CLI (`python -m src.leetcode`) uses it. Orchestrator (component 5) doesn't propagate a debug flag yet; if schema drift hits, the user has to invoke the CLI directly to dump raw responses.

---

## Components not yet built
- **Component 4** — `src/git_ops.py` (`commit_with_date`, `configure_git_identity`, `push`)
- **Component 5** — `src/main.py` (orchestrator — the integration glue + chronological ordering + per-problem folder writing + multi-language metadata.json append)

## Decisions worth remembering
- All env-var overrides use the `LEETCODE_SYNC_*` prefix (`LEETCODE_SYNC_MODEL`, `LEETCODE_SYNC_STATE_PATH`, `LEETCODE_SYNC_PROMPT_PATH`). Keep this convention for any new overrides.
- `run_tests.sh` is the entry point for tests (renamed from `test.sh` because of PowerShell tab-completion collision with the `tests/` directory).
- Plan is the source of truth — the CLAUDE.md tells future Claudes to read PLAN.md before writing code.
