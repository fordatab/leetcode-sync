# Unique Paths

**Difficulty:** Medium
**Tags:** dynamic-programming, grid, combinatorics

## Problem

Given an m-by-n grid, count the number of distinct paths from the top-left cell to the bottom-right cell, where each step can only move either right or down. The grid dimensions are both at least 1 and at most 100, and the answer is guaranteed to fit in a 32-bit integer.

## Approach

The solution uses a 2D dynamic programming table where `dp[x][y]` represents the number of unique paths to reach cell `(x, y)` from the starting position. The table is initialized with all zeros except `dp[0][0] = 1` since there's exactly one way to stay at the start. The algorithm iterates through each cell in row-major order. For each cell, it accumulates the number of paths from the cell directly above (if it exists) and the cell directly to the left (if it exists), since those are the only two cells from which the current cell can be reached. The final answer is stored in `dp[m-1][n-1]`, which represents the bottom-right corner.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-15 05:46 UTC
- Runtime: 4 ms
- Memory: 8 MB
- Language: C++
