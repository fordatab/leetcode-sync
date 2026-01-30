# Minimum Time to Finish the Race

**Difficulty:** Hard
**Tags:** dynamic-programming, greedy, precomputation, optimization

## Problem

Given an array of tires where each tire has a base time and a multiplier that exponentially increases lap time, along with a tire change time and total number of laps, find the minimum time to complete all laps. Each tire's x-th consecutive lap takes f * r^(x-1) seconds, and you can change tires between laps by paying the changeTime penalty. The goal is to decide when to switch tires to minimize total race time.

## Approach

The solution uses dynamic programming with precomputation. First, it precomputes `best[j]` for each possible consecutive lap count j, representing the minimum time to complete j consecutive laps using any single tire without changing. For each tire, it calculates cumulative times until either the next lap time exceeds `base + changeTime` (making a tire change more economical) or overflow would occur. The pruning condition `time > base + changeTime` ensures we don't compute unnecessarily long consecutive runs.

After precomputation, it builds a DP array where `dp[x]` represents the minimum time to complete x total laps. For each position x, it considers all ways to partition the remaining laps: completing the last j laps consecutively (using `best[j]`) after already completing x-j laps (using `dp[x-j]`). The changeTime is added for non-initial segments. The final answer is `dp[numLaps]`.

## Complexity

- **Time:** O(n * m + k^2)
- **Space:** O(k)

## Stats

- Submitted: 2026-01-30 23:01 UTC
- Runtime: 235 ms
- Memory: 236.7 MB
- Language: C++
