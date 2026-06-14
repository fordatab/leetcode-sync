# Earliest Finish Time for Land and Water Rides II

**Difficulty:** Medium
**Tags:** sorting, binary-search, greedy, prefix-suffix, two-pointer

## Problem

Given two categories of rides (land and water), each with start times and durations, find the earliest time a tourist can finish exactly one ride from each category. The tourist can choose the order of rides and must wait for a ride to open if they finish the previous ride before its start time. Input sizes can be up to 50,000 rides per category, with start times and durations up to 100,000.

## Approach

The solution splits the problem into two cases: land-first-then-water and water-first-then-land, computing the minimum for each.

For each ordering, it treats one category as "first" and the other as "second." The second category's rides are sorted by start time and preprocessed with two arrays: a prefix minimum of durations (for rides that open before the first ride finishes) and a suffix minimum of finish times (for rides that open after).

For each ride in the first category, binary search finds the split point in the sorted second category where rides transition from opening before/at the first ride's finish time to opening after. The minimum completion time is then computed by checking both groups: rides in the first group can start immediately after finishing the first ride (so we add the minimum duration), while rides in the second group require waiting (so we use their precomputed minimum finish time).

The overall answer is the minimum across both orderings.

## Complexity

- **Time:** O((n + m) log m)
- **Space:** O(m)

## Stats

- Submitted: 2026-06-14 01:30 UTC
- Runtime: 123 ms
- Memory: 257.3 MB
- Language: C++
