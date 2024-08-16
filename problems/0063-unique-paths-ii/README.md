# Unique Paths II

**Difficulty:** Medium
**Tags:** dynamic-programming, matrix, grid-traversal

## Problem

Given an m×n grid where cells contain either 0 (empty) or 1 (obstacle), count the number of unique paths from the top-left corner to the bottom-right corner. The robot can only move right or down, and cannot pass through obstacles. Grid dimensions are between 1 and 100 for both rows and columns.

## Approach

This solution uses dynamic programming with a 2D array where `dp[x][y]` represents the number of ways to reach cell (x, y) from the origin. 

The algorithm iterates through each cell in the grid:
- If a cell contains an obstacle (value 1), set `dp[x][y] = 0` since no paths can go through it
- For interior cells (both x and y are positive), the number of paths is the sum of paths from the cell above and the cell to the left: `dp[x][y] = dp[x-1][y] + dp[x][y-1]`
- For cells in the first row (x = 0), paths can only come from the left: `dp[x][y] = dp[x][y-1]`
- For cells in the first column (y = 0), paths can only come from above: `dp[x][y] = dp[x-1][y]`

The starting cell is initialized to 1, and the final answer is the value at the bottom-right corner.

## Complexity

- **Time:** O(m*n)
- **Space:** O(m*n)

## Stats

- Submitted: 2024-08-16 00:58 UTC
- Runtime: 2 ms
- Memory: 10.2 MB
- Language: C++
