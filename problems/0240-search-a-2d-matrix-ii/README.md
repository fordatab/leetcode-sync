# Search a 2D Matrix II

**Difficulty:** Medium
**Tags:** matrix, binary-search, two-pointers, divide-and-conquer

## Problem

Given an m×n matrix where each row is sorted left-to-right and each column is sorted top-to-bottom, determine whether a target value exists in the matrix. The matrix dimensions can be up to 300×300, and values range from -10^9 to 10^9.

## Approach

The solution uses a search-space elimination technique starting from the top-right corner of the matrix. It initializes pointers at position (0, n-1) and proceeds as follows:

- If the current element equals the target, return true immediately
- If the current element is greater than the target, move left (decrement x) because all elements below in that column are even larger
- If the current element is less than the target, move down (increment y) because all elements to the left in that row are even smaller

This strategy leverages the dual-sorted property: from the top-right corner, moving left decreases values and moving down increases values, allowing elimination of entire rows or columns with each comparison. The search continues until either the target is found or the pointers go out of bounds, at which point false is returned.

## Complexity

- **Time:** O(m + n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-17 00:41 UTC
- Runtime: 40 ms
- Memory: 17.7 MB
- Language: C++
