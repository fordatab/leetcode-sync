# Increasing Triplet Subsequence

**Difficulty:** Medium
**Tags:** greedy, array, two-pointers

## Problem

Given an integer array, determine whether there exist three indices i, j, k where i < j < k and the values at those indices are strictly increasing (nums[i] < nums[j] < nums[k]). The array can contain up to 500,000 elements with values ranging from -2^31 to 2^31 - 1.

## Approach

The solution uses a greedy two-pointer strategy with variables `i` and `j` to track the smallest and second-smallest values seen so far. Both are initialized to INT_MAX.

As we iterate through the array:
- If the current element is smaller than or equal to `i`, update `i` to be this element (we've found a potentially better starting point)
- Else if the current element is smaller than or equal to `j`, update `j` to be this element (we've found a better middle element)
- Otherwise, the current element is larger than both `i` and `j`, meaning we've found an increasing triplet, so return true

The key insight is that even if `i` gets updated after `j` is set, it doesn't invalidate `j` because there must have been a previous value smaller than `j` that existed before in the array. If we encounter any element larger than `j`, we're guaranteed to have a valid triplet with the original smaller value, the `j` value, and the current element.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-17 05:45 UTC
- Runtime: 76 ms
- Memory: 114.3 MB
- Language: C++
