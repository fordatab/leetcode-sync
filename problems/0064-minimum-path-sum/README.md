# Minimum Path Sum

**Difficulty:** Medium
**Tags:** dynamic-programming, grid, matrix

## Problem

Given an m×n grid of non-negative integers, find the path from the top-left corner to the bottom-right corner that produces the minimum sum of visited cells. Movement is restricted to rightward and downward steps only. The grid dimensions range from 1×1 to 200×200, and cell values are between 0 and 200.

## Approach

This solution uses dynamic programming with a 2D table where `dp[i][j]` represents the minimum path sum to reach cell (i,j) from the starting position.

The algorithm iterates through each cell row by row, left to right. For the top-left corner (0,0), the minimum sum is simply the cell's value. For cells in the first row, they can only be reached from the left, so the sum is the previous cell's sum plus the current value. Similarly, first-column cells can only be reached from above.

For all other cells, the minimum path sum is computed by taking the minimum of the cell above and the cell to the left, then adding the current cell's value. This choice reflects that any path to (i,j) must come from either (i-1,j) or (i,j-1), and we want the cheaper option.

The final answer is stored in `dp[m-1][n-1]`, representing the minimum sum to reach the bottom-right corner.

## Complexity

- **Time:** O(m*n)
- **Space:** O(m*n)

## Stats

- Submitted: 2024-08-16 00:06 UTC
- Runtime: 7 ms
- Memory: 13 MB
- Language: C++
