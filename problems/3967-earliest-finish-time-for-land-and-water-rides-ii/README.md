# Earliest Finish Time for Land and Water Rides II

**Difficulty:** Medium
**Tags:** sorting, binary-search, greedy, prefix-suffix, two-pointer

## Problem

Given two categories of attractions (land rides and water rides), each with start times and durations, find the earliest time a tourist can complete exactly one ride from each category. The rides can be taken in either order, and a ride can be started at or after its opening time. After finishing one ride, the tourist can immediately board the other if it's open, or wait until it opens.

## Approach

The solution considers both orderings (land-first then water, or water-first then land) and computes the minimum finish time for each.

For a fixed first-category ride, we need to efficiently find the best second-category ride. The code sorts the second category by start time, then precomputes two arrays: a prefix minimum of durations and a suffix minimum of finish times (start + duration).

Using binary search, it partitions the second category into rides that open before/at the first ride's finish time (where we start immediately and just add their duration) versus rides that open after (where we must wait and the total time is their own finish time). The prefix and suffix arrays allow constant-time lookups of the optimal ride in each partition.

This process repeats for each ride in the first category, tracking the global minimum. Finally, the solution returns the minimum across both orderings (land-first and water-first).

## Complexity

- **Time:** O((n + m) * log m)
- **Space:** O(m)

## Stats

- Submitted: 2026-06-14 01:30 UTC
- Runtime: 123 ms
- Memory: 257.3 MB
- Language: C++
