# Painting the Walls

**Difficulty:** Hard
**Tags:** dynamic-programming, knapsack, optimization

## Problem

Given n walls with associated costs and time durations for a paid painter, determine the minimum cost to paint all walls. A paid painter takes time[i] units to paint wall i at cost[i], while a free painter can paint any wall in 1 unit of time at zero cost, but only when the paid painter is actively working. The goal is to strategically assign walls to minimize total expenditure.

## Approach

This solution uses bottom-up dynamic programming where `dp[i][remain]` represents the minimum cost to paint when considering walls from index i onward with `remain` walls still needing to be covered.

The key insight is that when the paid painter works on a wall for `time[i]` units, the free painter can simultaneously paint `time[i]` additional walls. This transforms the problem into selecting which walls the paid painter should handle such that the total time covers all remaining walls.

For each wall, we have two choices: (1) assign it to the paid painter, paying `cost[i]` and reducing the remaining walls by `1 + time[i]` (the wall itself plus the walls the free painter can cover), or (2) skip assigning it to the paid painter. The recurrence computes the minimum of these two options.

The base case initializes `dp[n][i]` to a large value (1e9) for any positive remaining walls when all walls have been considered, and to 0 when no walls remain. The answer is `dp[0][n]`, representing the minimum cost starting from wall 0 with n walls to paint.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n^2)

## Stats

- Submitted: 2025-11-28 10:30 UTC
- Runtime: 49 ms
- Memory: 121.9 MB
- Language: C++
