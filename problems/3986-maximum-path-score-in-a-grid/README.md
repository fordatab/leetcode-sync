# Maximum Path Score in a Grid

**Difficulty:** Medium
**Tags:** dynamic-programming, grid, path-finding

## Problem

Given an m×n grid where each cell contains 0, 1, or 2, find a path from top-left to bottom-right (moving only right or down) that maximizes score while staying within a cost budget k. Cells with value 0 contribute 0 score and 0 cost; cells with value 1 contribute 1 score and 1 cost; cells with value 2 contribute 2 score and 1 cost. Return the maximum achievable score, or -1 if no valid path exists within the budget.

## Approach

This solution uses three-dimensional dynamic programming where `dp[x][y][c]` represents the maximum score achievable when starting from cell (x, y) and having exactly c units of remaining budget.

The algorithm iterates through all possible budget levels from 0 to k (outer loop), and for each budget level, processes grid cells in reverse order (from bottom-right toward top-left). For each cell, it calculates the cost of stepping on that cell (1 if the cell value is 1 or 2, otherwise 0), then looks at the maximum scores achievable from the two possible next positions (right and down) with the reduced budget (c minus the current cell's cost).

The base case initializes the destination cell (m-1, n-1) with its own grid value when sufficient budget remains. For each other cell, the algorithm computes the maximum score by adding the current cell's value to the best achievable score from adjacent cells. The final answer is read from `dp[0][0][k]`, representing the maximum score starting from the top-left with full budget k.

## Complexity

- **Time:** O(m × n × k)
- **Space:** O(m × n × k)

## Stats

- Submitted: 2026-05-07 23:51 UTC
- Runtime: 1292 ms
- Memory: 499.3 MB
- Language: C++
