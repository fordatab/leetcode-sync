# Sum of Absolute Differences in a Sorted Array

**Difficulty:** Medium
**Tags:** prefix-sum, array, math

## Problem

Given a sorted array of integers in non-decreasing order, compute for each element the sum of absolute differences between that element and all other elements in the array. The array can have up to 10^5 elements with values ranging from 1 to 10^4.

## Approach

The solution uses prefix and suffix sum arrays to avoid recomputing sums for each position. First, it builds a prefix sum array where `prefix[i]` contains the sum of all elements from index 0 to i. Similarly, it builds a suffix sum array where `suffix[i]` contains the sum from index i to the end.

For each index i, the total absolute difference sum is split into two parts: differences with elements to the left and differences with elements to the right. Since the array is sorted, all elements to the left are ≤ nums[i], so their absolute differences equal `nums[i] * count_left - sum_left`. Similarly, elements to the right are ≥ nums[i], so their differences equal `sum_right - nums[i] * count_right`.

The code handles three cases separately (first element, last element, and middle elements) using the precomputed prefix and suffix sums. For middle elements, it calculates `(nums[i] * i) - prefix[i-1]` for the left side and `suffix[i+1] - (nums[i] * (n-i-1))` for the right side, then sums them to get the result.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-03-03 01:59 UTC
- Runtime: 77 ms
- Memory: 92 MB
- Language: C++
