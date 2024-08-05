# Set Matrix Zeroes

**Difficulty:** Medium
**Tags:** matrix, hash-table, two-pass

## Problem

Given an m×n matrix, modify it in-place so that whenever a cell contains zero, its entire row and column are set to zero. The matrix dimensions range from 1×1 to 200×200, and cell values can be any 32-bit signed integer. The challenge emphasizes minimizing space usage beyond the input matrix itself.

## Approach

This solution uses two hash sets to track which rows and columns need to be zeroed. In the first pass, it scans the entire matrix and records the row index in set `r` and column index in set `c` whenever a zero is encountered. In the second pass, it iterates through the matrix again and sets any cell to zero if its row index exists in `r` or its column index exists in `c`. This two-pass approach cleanly separates the detection phase from the modification phase, avoiding the issue of newly-written zeros triggering additional changes.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m + n)

## Stats

- Submitted: 2024-08-05 06:17 UTC
- Runtime: 9 ms
- Memory: 17.3 MB
- Language: C++
