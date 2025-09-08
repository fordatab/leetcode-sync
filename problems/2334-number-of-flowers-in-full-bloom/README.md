# Number of Flowers in Full Bloom

**Difficulty:** Hard
**Tags:** binary-search, sorting, array, line-sweep

## Problem

Given intervals representing when flowers bloom and query times when people arrive, determine how many flowers are blooming at each person's arrival time. Each flower blooms from a start time to an end time (inclusive), and we need to count overlapping intervals for each query. The input can have up to 50,000 flowers and 50,000 people, with time values up to 10^9.

## Approach

The solution uses a difference array concept implemented with binary search. It separates flower bloom intervals into two sorted arrays: one containing all start times and another containing all end times plus one (to handle the inclusive end). For each person's arrival time, it uses `upper_bound` to count how many flowers have started blooming (by finding how many start times are less than or equal to the person's time) and how many have finished blooming (by finding how many end+1 times are less than or equal to the person's time). The difference between these counts gives the number of flowers currently in bloom. This works because a flower is blooming at time `t` if its start is ≤ `t` and its end+1 is > `t`.

## Complexity

- **Time:** O((n + m) log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-08 11:26 UTC
- Runtime: 39 ms
- Memory: 86.7 MB
- Language: C++
