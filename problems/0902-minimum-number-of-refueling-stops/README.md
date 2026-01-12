# Minimum Number of Refueling Stops

**Difficulty:** Hard
**Tags:** dynamic-programming, greedy, array

## Problem

Given a target distance, initial fuel amount, and a list of gas stations (each with a position and fuel amount), determine the minimum number of refueling stops needed to reach the target. The car consumes one unit of fuel per mile traveled. If the destination cannot be reached, return -1. Constraints include up to 500 stations and distances/fuel amounts up to 10^9.

## Approach

This solution uses dynamic programming where `dp[i]` represents the maximum distance reachable using exactly `i` refueling stops.

The algorithm iterates through each gas station in order. For each station, it updates the DP array in reverse order (from higher stop counts down to 1) to avoid using the same station multiple times in one iteration. If the car can reach station `x` with `i-1` stops (meaning `dp[i-1] >= stations[x][0]`), then with `i` stops we can potentially reach `dp[i-1] + stations[x][1]` distance by refueling at this station.

The reverse iteration is crucial: it ensures that when processing station `x`, we only consider states from before this station was available, preventing double-counting. After processing all stations, the algorithm scans the DP array to find the minimum number of stops where the maximum reachable distance meets or exceeds the target.

The solution correctly handles edge cases like reaching the target without any stops (when `dp[0] = startFuel >= target`) and impossible scenarios where no combination of stops suffices.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-12 23:44 UTC
- Runtime: 12 ms
- Memory: 20.3 MB
- Language: C++
