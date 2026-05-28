# Maximum Path Score in a Grid

**Difficulty:** Medium
<<<<<<< HEAD
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
=======
**Tags:** dynamic-programming, grid, path-finding, constrained-optimization

## Problem

Given an m×n grid where cells contain values 0, 1, or 2, find a path from top-left to bottom-right (moving only right or down) that maximizes score while staying within a cost budget k. Cell value 0 adds 0 score and costs 0; value 1 adds 1 score and costs 1; value 2 adds 2 score and costs 1. Return the maximum achievable score, or -1 if no valid path exists within the cost constraint.

## Approach

This solution uses three-dimensional dynamic programming where `dp[i][j][c]` represents the maximum score achievable when reaching cell (i, j) with exactly cost c consumed.

The algorithm initializes `dp[0][0][0] = 0` since we start at the top-left with zero score and zero cost. It then iterates through all cells in row-major order, and for each valid state `dp[i][j][c]`, attempts to transition to the right neighbor (i, j+1) and down neighbor (i+1, j).

For each transition, it calculates the cost increment (0 if cell value is 0, otherwise 1) and the score increment (equal to the cell value). If the new total cost doesn't exceed k, it updates the destination state with the maximum of its current value and the current score plus the cell's value.

Finally, it examines all possible cost values at the destination cell (m-1, n-1) to find the maximum score achieved, returning -1 if no valid path exists.

## Complexity

- **Time:** O(m * n * k)
- **Space:** O(m * n * k)

## Stats

- Submitted: 2026-05-08 02:45 UTC
- Runtime: 732 ms
- Memory: 499.4 MB
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
