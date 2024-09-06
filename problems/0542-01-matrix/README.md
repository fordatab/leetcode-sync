# 01 Matrix

**Difficulty:** Medium
**Tags:** dynamic-programming, matrix, multi-pass

## Problem

Given a binary matrix containing 0s and 1s, compute the shortest Manhattan distance from each cell to any cell containing a 0. Cells sharing an edge are considered distance 1 apart. The matrix dimensions can be up to 10^4 cells total, and at least one 0 is guaranteed to exist.

## Approach

This solution uses dynamic programming with multiple directional passes to propagate distance information. It initializes a DP table with a large value (10000) for all cells, then sets cells containing 0 in the original matrix to distance 0.

The algorithm performs four complete sweeps over the matrix in different directions: top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, and bottom-left to top-right. During each sweep, for cells containing 1, it checks all four neighboring cells (up, down, left, right) and updates the current cell's distance to be the minimum of its current value and any neighbor's distance plus 1.

By making multiple passes in different directions, the algorithm ensures that distance information propagates from all zeros throughout the entire matrix. Each pass allows distances to flow in different directions, and after sufficient iterations, all cells converge to their correct minimum distances.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-09-06 01:03 UTC
- Runtime: 51 ms
- Memory: 31.3 MB
- Language: C++
