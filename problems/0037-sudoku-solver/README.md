# Sudoku Solver

**Difficulty:** Hard
**Tags:** backtracking, recursion, matrix, constraint-satisfaction

## Problem

Given a partially filled 9×9 grid representing a sudoku puzzle (with empty cells marked as '.'), fill all empty cells such that each row, column, and 3×3 sub-box contains the digits 1–9 exactly once. The input is guaranteed to have exactly one valid solution.

## Approach

This solution uses recursive backtracking to fill the board cell by cell, proceeding row by row from left to right. The `bt` function takes coordinates (x, y) and recursively moves to the next cell, returning true when all cells are successfully filled (when x reaches 9).

For each empty cell, the algorithm tries placing digits 1 through 9. Before placing a digit, the `isValid` helper checks whether that digit already exists in the current row, column, or 3×3 box by iterating through all 9 positions in each. The box check uses the formula `3 * (row / 3) + i / 3` and `3 * (col / 3) + i % 3` to map the loop index to the corresponding box position.

If a digit placement is valid, it's placed on the board and the recursion continues to the next cell. If the recursion eventually succeeds, the solution propagates back up by returning true. If it fails, the algorithm backtracks by resetting the cell to '.' and trying the next digit. Cells that are already filled are skipped automatically.

## Complexity

- **Time:** O(9^m)
- **Space:** O(m)

## Stats

- Submitted: 2026-01-12 04:40 UTC
- Runtime: 345 ms
- Memory: 8.8 MB
- Language: C++
