# Maximum Subarray

**Difficulty:** Medium
**Tags:** array, dynamic-programming, kadane-algorithm, greedy

## Problem

Given an array of integers, identify the contiguous subsequence whose elements sum to the maximum possible value and return that sum. The array has length between 1 and 100,000, with individual elements ranging from -10,000 to 10,000.

## Approach

This solution implements Kadane's algorithm, which solves the maximum subarray problem in a single pass through the array.

Two variables are maintained: `curr` tracks the maximum sum of any subarray ending at the current position, and `result` stores the overall maximum encountered so far. Both are initialized to the first element.

For each subsequent element, we decide whether to extend the existing subarray (by adding the current element to `curr`) or start fresh from the current element alone—whichever yields a larger sum. This decision is captured by `curr = max(curr + nums[i], nums[i])`.

After updating `curr`, we compare it against `result` and update the global maximum if necessary. By the end of the iteration, `result` contains the maximum subarray sum found anywhere in the array.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 08:41 UTC
- Runtime: 71 ms
- Memory: 70.7 MB
- Language: C++
