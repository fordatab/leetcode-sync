# Partition Array for Maximum Sum

**Difficulty:** Medium
**Tags:** dynamic-programming, array, sliding-window

## Problem

Given an integer array, divide it into contiguous segments where each segment has at most k elements. Within each segment, replace all values with the segment's maximum value. The goal is to find the partitioning that maximizes the sum of all elements after this transformation. The array can have up to 500 elements, with values ranging from 0 to 10^9, and k is between 1 and the array length.

## Approach

This solution uses dynamic programming where `dp[i]` represents the maximum sum achievable for the first `i` elements of the array.

For each position `i` from 1 to n, the algorithm considers all possible ways to form the last partition ending at position `i`. It tries partition sizes from 1 to k (as long as we don't go past the array start).

For each potential partition size `j`, it tracks the maximum value in that partition by iterating backwards from position `i`. The key insight is that if we partition the last `j` elements into one group, we can replace all `j` elements with their maximum value, contributing `maxVal * j` to the sum, plus the optimal sum for the remaining elements `dp[i - j]`.

The algorithm updates `dp[i]` by taking the maximum across all valid partition sizes, ensuring we find the optimal partitioning strategy for each prefix of the array.

## Complexity

- **Time:** O(n * k)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-06 03:20 UTC
- Runtime: 7 ms
- Memory: 11.3 MB
- Language: C++
