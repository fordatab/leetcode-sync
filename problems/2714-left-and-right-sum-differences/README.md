# Left and Right Sum Differences

**Difficulty:** Easy
**Tags:** prefix-sum, array, math

## Problem

Given an array of integers, compute two auxiliary arrays: one holding the sum of all elements to the left of each index, and another holding the sum of all elements to the right of each index. Return an array where each element is the absolute difference between the corresponding left and right sums. The input array has length between 1 and 1000, with element values up to 100,000.

## Approach

The solution builds two prefix-sum arrays:

1. Array `l` accumulates elements from left to right, where `l[i]` is the cumulative sum up to and including index `i`.
2. Array `r` accumulates elements from right to left, where `r[i]` is the cumulative sum from index `i` to the end.

After constructing these arrays in a single forward loop, the code assembles the result by computing absolute differences. For the first position, it uses `r[1]` (sum of everything to the right). For middle positions, it takes `abs(l[x-1] - r[x+1])` (sum strictly left vs. sum strictly right). For the last position, it uses `l[n-2]` (sum of everything to the left). This approach effectively translates the cumulative sums into the required left-only and right-only sums through careful indexing.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-30 07:06 UTC
- Runtime: 7 ms
- Memory: 13.8 MB
- Language: C++
