# Maximum Number of Events That Can Be Attended II

**Difficulty:** Hard
**Tags:** dynamic-programming, binary-search, sorting, interval-scheduling

## Problem

Given a list of events where each event has a start day, end day, and value, find the maximum sum of values you can obtain by attending at most k non-overlapping events. Events cannot overlap (if one ends on day d, another cannot start on day d), and you must attend each chosen event for its entire duration. The constraint k * events.length ≤ 10^6 indicates moderate input sizes, and days can range up to 10^9.

## Approach

The solution uses dynamic programming with events sorted by end time. It defines a `Job` struct to hold start, end, and profit for each event, then sorts all jobs by their end day. A 2D DP table `dp[i][j]` represents the maximum value achievable using the first i events and attending at most j of them.

For each event i and count j, the algorithm considers two choices: skip the current event (inherit `dp[i-1][j]`) or take it. When taking event i, it uses binary search (`lower_bound`) on a sorted array of end times to find the latest non-overlapping previous event whose end day is strictly before the current event's start day. The value from taking the event is its profit plus `dp[idx][j-1]` where idx is the found position.

The base case initializes `dp[0][y]` to the first job's profit for all y ≥ 1. The final answer is `dp[n-1][k]`, representing the maximum value using all n events with up to k attendances.

## Complexity

- **Time:** O(n log n + n * k * log n)
- **Space:** O(n * k)

## Stats

- Submitted: 2025-12-01 11:14 UTC
- Runtime: 219 ms
- Memory: 162.5 MB
- Language: C++
