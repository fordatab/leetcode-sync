# Count Negative Numbers in a Sorted Matrix

**Difficulty:** Easy
**Tags:** binary-search, matrix, array

## Problem

Given an m×n matrix where each row and column is sorted in non-increasing (descending) order, count how many negative numbers appear in the entire matrix. The matrix dimensions are between 1×1 and 100×100, with values ranging from -100 to 100.

## Approach

The solution processes each row independently using binary search to find the transition point from non-negative to negative values. For each row, it performs a standard binary search where the right pointer moves left when a negative number is found, and the left pointer moves right when a non-negative number is found. After the binary search completes (when `l > r`), the variable `r` points to the last non-negative index in the row. The count of negative numbers in that row is then `arr.size() - r - 1`, which represents all elements after the last non-negative position. This count is accumulated across all rows to produce the total.

## Complexity

- **Time:** O(m log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-14 21:39 UTC
- Runtime: 10 ms
- Memory: 13.6 MB
- Language: C++
