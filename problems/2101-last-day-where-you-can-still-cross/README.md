# Last Day Where You Can Still Cross

**Difficulty:** Hard
**Tags:** binary-search, breadth-first-search, grid, matrix

## Problem

Given a row×col grid that starts entirely as land, cells flood with water one per day according to a given sequence. The task is to find the latest day on which you can still walk from any cell in the top row to any cell in the bottom row using only land cells and moving in four cardinal directions. The cells array specifies which cell floods on each day (1-indexed), and all cells eventually flood.

## Approach

The solution uses binary search on the answer combined with BFS path verification. For each candidate day in the binary search, it reconstructs the grid state by marking all cells that have flooded up to that day as water. Then it runs BFS starting from all land cells in the top row, exploring only land cells via four-directional moves. If any path reaches the bottom row, that day is feasible; the search then tries a later day. Otherwise, it tries an earlier day. The binary search narrows down to the last day where a top-to-bottom path exists.

The key insight is that if crossing is possible on day k, it's also possible on all days before k, making the problem monotonic and suitable for binary search. Each BFS check costs O(row × col) time, and the binary search runs O(log(row × col)) iterations since there are at most row × col days.

## Complexity

- **Time:** O(row * col * log(row * col))
- **Space:** O(row * col)

## Stats

- Submitted: 2026-01-14 05:13 UTC
- Runtime: 407 ms
- Memory: 263 MB
- Language: C++
