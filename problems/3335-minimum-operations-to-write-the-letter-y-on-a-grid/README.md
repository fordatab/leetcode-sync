# Minimum Operations to Write the Letter Y on a Grid

**Difficulty:** Medium
**Tags:** array, matrix, enumeration, frequency-counting

## Problem

Given an n×n grid (n is odd) where each cell contains 0, 1, or 2, determine the minimum operations needed to form a letter Y pattern. The Y consists of two diagonals from the top corners meeting at the center, plus a vertical line from center to bottom. All cells in the Y must have the same value, all cells outside the Y must have a different same value, and these two values must differ from each other. Each operation changes one cell to any value 0, 1, or 2.

## Approach

The solution identifies which cells belong to the Y pattern and which don't. It maintains two frequency arrays: one counting the values (0, 1, or 2) in Y cells, and another for non-Y cells.

First, it iterates through the grid to mark Y cells: the top-left to center diagonal, top-right to center diagonal, and the vertical line from center to bottom. It counts how many of each value (0, 1, 2) appear in Y positions.

Then it counts all cell values in the entire grid and subtracts the Y counts to get the frequency distribution of non-Y cells.

Finally, it tries all valid combinations where Y cells become value x and non-Y cells become value y (where x ≠ y). For each combination, it calculates the cost as (total Y cells - cells already having value x) + (total non-Y cells - cells already having value y), keeping track of the minimum.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2025-08-31 07:59 UTC
- Runtime: 76 ms
- Memory: 41.9 MB
- Language: C++
