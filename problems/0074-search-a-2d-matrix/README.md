# Search a 2D Matrix

**Difficulty:** Medium
**Tags:** binary-search, matrix, array

## Problem

Given an m×n matrix where each row is sorted in ascending order and the first element of each row is greater than the last element of the previous row, determine whether a target integer exists in the matrix. The solution must run in O(log(m×n)) time, treating the matrix dimensions as up to 100×100 with values ranging from -10⁴ to 10⁴.

## Approach

The solution treats the 2D matrix as a flattened 1D sorted array and performs binary search on it. It initializes left and right pointers to 0 and (m×n - 1) respectively.

For each iteration, it calculates the middle index and converts it back to 2D coordinates: row = mid / columns, column = mid % columns. This mapping allows direct access to matrix elements while maintaining binary search logic.

The binary search proceeds normally: if the element at the computed position equals the target, return true; if it's less than the target, move the left pointer up; otherwise, move the right pointer down. If the search completes without finding the target, return false.

## Complexity

- **Time:** O(log(m * n))
- **Space:** O(1)

## Stats

- Submitted: 2024-07-02 04:48 UTC
- Runtime: 3 ms
- Memory: 11.9 MB
- Language: C++
