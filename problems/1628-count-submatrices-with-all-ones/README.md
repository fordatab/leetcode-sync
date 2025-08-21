# Count Submatrices With All Ones

**Difficulty:** Medium
**Tags:** dynamic-programming, matrix, prefix-sum, enumeration

## Problem

Given an m×n binary matrix, count how many rectangular submatrices contain only ones. A submatrix is defined by choosing any top-left and bottom-right corner such that all cells within that rectangle are 1. The matrix dimensions can be up to 150×150.

## Approach

The solution uses a two-pass algorithm. First, it builds a preprocessing table `width[i][j]` that stores the count of consecutive 1s ending at position (i,j) in row i, moving left to right. This gives us the maximum horizontal extent of ones at each cell.

In the second phase, for each cell (i,j) that contains a 1, the algorithm treats it as the bottom-right corner of potential rectangles and explores upward (decreasing row index k from i to 0). For each row k, it tracks the minimum width encountered so far when going upward—this minimum represents the maximum width of any rectangle spanning from row k to row i and ending at column j.

For each valid upward extension to row k, the algorithm adds `minW` to the answer, representing all rectangles with bottom-right at (i,j), top row at k, and varying widths from 1 to minW. The iteration stops when encountering a 0 (width[k][j] == 0) since no rectangle can extend further upward.

## Complexity

- **Time:** O(m * n * m)
- **Space:** O(m * n)

## Stats

- Submitted: 2025-08-21 11:10 UTC
- Runtime: 15 ms
- Memory: 19.5 MB
- Language: C++
