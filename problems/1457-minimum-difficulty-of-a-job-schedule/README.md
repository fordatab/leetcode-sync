# Minimum Difficulty of a Job Schedule

**Difficulty:** Hard
**Tags:** dynamic-programming, array, scheduling

## Problem

Given an array of job difficulties and a number of days, partition the jobs into exactly d consecutive groups (one group per day) such that each day has at least one job. Jobs must be completed in order. The difficulty of each day equals the maximum difficulty among jobs assigned to that day. Find the minimum total difficulty (sum of daily difficulties) across all valid schedules, or return -1 if no valid schedule exists.

## Approach

The solution uses dynamic programming with states `dp[day][i]` representing the minimum total difficulty to complete the first `i` jobs using exactly `day` days.

For each day from 1 to d and each job count from day to n, it tries all possible split points where the previous days handle the first k jobs and the current day handles jobs from index k to i-1. As it iterates backward through possible values of k, it maintains a running maximum of job difficulties for the current day's range.

The base case is `dp[0][0] = 0` (zero jobs in zero days costs nothing). For each state, it computes the minimum by trying all valid previous states and adding the maximum difficulty of jobs assigned to the current day. The final answer is `dp[d][n]`, representing all n jobs scheduled across d days.

## Complexity

- **Time:** O(n^2 * d)
- **Space:** O(n * d)

## Stats

- Submitted: 2026-01-25 10:25 UTC
- Runtime: 18 ms
- Memory: 11.1 MB
- Language: C++
