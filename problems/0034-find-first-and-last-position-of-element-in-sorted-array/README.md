# Find First and Last Position of Element in Sorted Array

**Difficulty:** Medium
**Tags:** binary-search, array, two-pointers

## Problem

Given a sorted array of integers in non-decreasing order, locate the first and last indices where a target value appears. If the target is absent, return [-1, -1]. The solution must achieve O(log n) time complexity, with array sizes up to 100,000 elements and values ranging from -10^9 to 10^9.

## Approach

The solution implements a custom binary search helper function `lower_bound` that finds the leftmost position where a value could be inserted while maintaining sorted order.

To find the range, it performs two binary searches: first, it finds the leftmost occurrence of `target` by calling `lower_bound(target)`. Then it finds the position just after the rightmost occurrence by calling `lower_bound(target+1)` and subtracting 1.

The binary search uses the standard technique: maintain left and right pointers, compute the midpoint, and move the search window based on whether the middle element is less than the target. When `nums[mid] < target`, search the right half; otherwise, search the left half.

Finally, it validates that the first index actually contains the target value (to handle cases where the target doesn't exist) before returning the range [idx1, idx2].

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-28 06:15 UTC
- Runtime: 11 ms
- Memory: 16.4 MB
- Language: C++
