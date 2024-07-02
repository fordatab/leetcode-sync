# Find Minimum in Rotated Sorted Array

**Difficulty:** Medium
**Tags:** binary-search, array, divide-and-conquer

## Problem

Given an array that was originally sorted in ascending order but has been rotated some number of positions, find the minimum element. All elements are unique, the array length is between 1 and 5000, and values range from -5000 to 5000. The solution must run in O(log n) time.

## Approach

The solution uses binary search with modifications to handle the rotated array. It maintains left and right pointers and tracks the minimum seen so far.

At each iteration, if the subarray from left to right is sorted (left value less than right value), it updates the result with the left value and exits early since that's the minimum for a sorted portion.

Otherwise, it calculates the middle index and updates the result with the middle value. It then determines which half contains the rotation point: if the middle value is greater than or equal to the left value, the left half is sorted and the minimum must be in the right half, so it moves left pointer past mid. Otherwise, the rotation point is in the left half, so it moves the right pointer before mid.

This approach efficiently narrows down the search space by eliminating the sorted half at each step, converging on the minimum element where the rotation occurs.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-02 09:11 UTC
- Runtime: 3 ms
- Memory: 12.7 MB
- Language: C++
