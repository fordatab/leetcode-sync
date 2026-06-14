# Earliest Finish Time for Land and Water Rides I

**Difficulty:** Easy
**Tags:** brute-force, nested-loops, greedy, simulation

## Problem

Given lists of start times and durations for land rides and water rides, find the minimum total time to complete exactly one ride from each category. The tourist can do the rides in either order, may start a ride at its opening time or later, and can immediately board the second ride after finishing the first (if it has already opened) or wait until it opens.

## Approach

The solution uses a brute-force approach to examine all possible combinations of one land ride and one water ride in both possible orderings.

For each pair (land ride i, water ride j), it calculates two scenarios:
1. **Land first, then water**: Complete land ride i (finishing at `landStartTime[i] + landDuration[i]`), then start water ride j at the later of this finish time or `waterStartTime[j]`, finishing at that start time plus `waterDuration[j]`.
2. **Water first, then land**: Complete water ride j (finishing at `waterStartTime[j] + waterDuration[j]`), then start land ride i at the later of this finish time or `landStartTime[i]`, finishing at that start time plus `landDuration[i]`.

The minimum finish time across all these scenarios (2 × n × m total) is tracked and returned as the result.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-14 00:16 UTC
- Runtime: 19 ms
- Memory: 91.7 MB
- Language: C++
