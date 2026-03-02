# Maximum Median Sum of Subsequences of Size 3

**Difficulty:** Medium
**Tags:** sorting, greedy, math

## Problem

Given an integer array whose length is divisible by 3, repeatedly select three elements, compute their median, remove them, and sum all the medians. The goal is to maximize this sum. The array length can be up to 500,000, and element values range from 1 to 10^9.

## Approach

The solution sorts the entire array in non-decreasing order. After sorting, it greedily selects medians by iterating backward from index `n-2` (the second-largest element) down to index `n/3`, stepping by 2 each time. This pattern ensures that for each group of three elements we conceptually form, we pick the middle value from the upper portion of the sorted array. By starting at `n-2` and decrementing by 2, we effectively pair each selected median with two other elements (one smaller, one larger from the remaining pool) to maximize the median values. The key insight is that to maximize the sum of medians, we want the medians themselves to be as large as possible, which is achieved by selecting from the higher end of the sorted array in this systematic pattern.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-02 11:53 UTC
- Runtime: 47 ms
- Memory: 174.3 MB
- Language: C++
