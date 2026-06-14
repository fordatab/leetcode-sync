# Earliest Finish Time for Land and Water Rides I

**Difficulty:** Easy
**Tags:** brute-force, greedy, array, enumeration

## Problem

Given arrays of start times and durations for land rides and water rides, determine the earliest time a tourist can complete exactly one ride from each category. The tourist may take the rides in either order, can start a ride at its opening time or later, and can immediately board the next ride after finishing the first (if it's already open) or wait until it opens.

## Approach

The solution uses a brute-force approach that examines all possible pairings of land and water rides in both possible orderings. For each land ride and water ride combination, it calculates two scenarios:

1. **Land-first scenario**: Complete the land ride (finishing at `landStartTime[i] + landDuration[i]`), then start the water ride at the maximum of this finish time and the water ride's opening time, computing the total finish time.

2. **Water-first scenario**: Complete the water ride (finishing at `waterStartTime[j] + waterDuration[j]`), then start the land ride at the maximum of this finish time and the land ride's opening time, computing the total finish time.

The algorithm maintains a running minimum across all scenario finish times. The `max` function ensures that if a ride isn't yet open when the previous ride finishes, the tourist waits until it opens. This exhaustive enumeration guarantees finding the optimal pairing and ordering.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-14 00:16 UTC
- Runtime: 19 ms
- Memory: 91.7 MB
- Language: C++
