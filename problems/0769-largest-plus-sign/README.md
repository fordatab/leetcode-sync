# Largest Plus Sign

**Difficulty:** Medium
**Tags:** dynamic-programming, matrix, prefix-sum, grid

## Problem

Given an n×n grid initially filled with 1s except at positions specified in a mines array (which are 0s), find the largest axis-aligned plus sign that can be formed. A plus sign of order k has a center cell and four arms extending k-1 cells in each cardinal direction (up, down, left, right), all containing 1s. The grid size can be up to 500×500 with up to 5000 mines.

## Approach

The solution uses dynamic programming to precompute the maximum consecutive 1s extending from each cell in all four directions. It creates a 3D DP table where `dp[i][j][d]` stores the count of consecutive 1s from position (i,j) in direction d (0=up, 1=down, 2=right, 3=left). The algorithm performs four separate passes through the grid:

1. Top-to-bottom pass to compute upward arm lengths
2. Bottom-to-top pass to compute downward arm lengths  
3. Right-to-left pass to compute rightward arm lengths
4. Left-to-right pass to compute leftward arm lengths

After building the DP table, it iterates through all non-zero cells and computes the plus sign order at each position by taking the minimum of the four directional arm lengths. The maximum order across all cells is returned as the answer.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-09-04 07:54 UTC
- Runtime: 502 ms
- Memory: 227 MB
- Language: C++
