# Maximum Profit in Job Scheduling

**Difficulty:** Hard
**Tags:** dynamic-programming, binary-search, sorting, greedy

## Problem

Given n jobs with start times, end times, and profits, find the maximum profit achievable by selecting non-overlapping jobs. Jobs are allowed to share an endpoint (one can start exactly when another ends). Input arrays can contain up to 50,000 jobs, with time values up to 10^9 and profits up to 10^4.

## Approach

The solution uses dynamic programming with jobs sorted by end time. It creates a Job struct to bundle each job's attributes, then sorts all jobs by their end times in ascending order. A DP array tracks the maximum profit achievable up to each job index. For each job, it computes two options: skip the current job (inherit previous maximum) or take it by finding the latest non-conflicting job using binary search on a separately sorted endTime array. The binary search (upper_bound) locates the rightmost job that ends at or before the current job's start time, allowing safe concatenation of their profits. The final answer is the maximum profit at the last position.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-01 10:47 UTC
- Runtime: 30 ms
- Memory: 80.3 MB
- Language: C++
