# Maximum Coins From K Consecutive Bags

**Difficulty:** Medium
**Tags:** sliding-window, prefix-sum, sorting, greedy, intervals

## Problem

Given non-overlapping intervals on a number line where each interval [left, right, coins_per_bag] specifies that every position from left to right contains coins_per_bag coins, find the maximum total coins obtainable by selecting k consecutive positions. The number of intervals can reach 10^5, positions can range up to 10^9, and k can be up to 10^9.

## Approach

The solution sorts the intervals by their left endpoints and computes a prefix sum array storing cumulative coins up to each interval's right endpoint. It then uses two separate sliding window passes to find the maximum coins in any k-consecutive positions.

In the first pass (right-to-left window), for each interval as the right boundary, it advances a left pointer to find where the k-window would start, calculates coins from fully-covered intervals between them, and adds coins from the partial overlap with the leftmost interval.

In the second pass (left-to-right window), for each interval as the left boundary, it advances a right pointer to find where the k-window would end, calculates coins from fully-covered intervals, and adds coins from the partial overlap with the rightmost interval.

Both passes use the precomputed prefix sums for efficient range queries, and the maximum across all windows is tracked and returned.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-06-13 09:24 UTC
- Runtime: 91 ms
- Memory: 173.6 MB
- Language: C++
