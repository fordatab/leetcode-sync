# Cherry Pickup

**Difficulty:** Hard
**Tags:** dynamic-programming, grid, path-finding, memoization

## Problem

Given an n×n grid where cells contain either a cherry (1), empty space (0), or a thorn (-1), find the maximum cherries collectible by moving from the top-left to bottom-right (only right/down moves allowed), then returning to top-left (only left/up moves allowed). When a cherry is picked, that cell becomes empty. If no valid path exists between corners, return 0. The grid size ranges from 1 to 50.

## Approach

The solution reframes the round-trip problem as two people simultaneously walking from (0,0) to (n-1,n-1), both only moving right or down. This is mathematically equivalent to one person making a round trip because the return path can be seen as a second forward path traversed in parallel.

A 3D DP table `dp[t][r1][r2]` tracks the maximum cherries collected when both walkers have taken `t` steps, with walker 1 at row `r1` and walker 2 at row `r2`. The column positions are derived as `c1 = t - r1` and `c2 = t - r2` since each step increases row+column by 1.

For each timestep from 1 to `2(n-1)`, the code considers all valid positions for both walkers. It transitions from four possible previous states (each walker could have moved either right or down). When both walkers occupy the same cell, only one cherry is counted to avoid double-counting.

The answer is `dp[2(n-1)][n-1][n-1]`, representing both walkers reaching the bottom-right corner, or 0 if no valid path exists (indicated by the sentinel value -1e9).

## Complexity

- **Time:** O(n^3)
- **Space:** O(n^3)

## Stats

- Submitted: 2025-12-02 11:18 UTC
- Runtime: 41 ms
- Memory: 40.8 MB
- Language: C++
