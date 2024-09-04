# Count Square Submatrices with All Ones

**Difficulty:** Medium
**Tags:** dynamic-programming, matrix, bottom-up-dp

## Problem

Given a binary matrix of dimensions m×n containing only zeros and ones, count the total number of square submatrices (of any size) that consist entirely of ones. The matrix dimensions can be up to 300×300, and each cell contains either 0 or 1.

## Approach

This solution uses dynamic programming to count all square submatrices. It creates a DP table `dp[i+1][j+1]` where each entry represents the side length of the largest square with its bottom-right corner at position `(i, j)` in the original matrix.

For each cell containing a 1, the DP value is computed as the minimum of the three neighboring cells (left, top, and top-left diagonal) plus one. This works because a square of side length k can only exist if all three neighboring positions can form squares of at least side length k-1.

The key insight is that if `dp[i][j] = k`, it means there are k squares with bottom-right corner at that position: one 1×1 square, one 2×2 square, ..., up to one k×k square. Therefore, summing all DP values gives the total count of all square submatrices.

The solution uses 1-indexed DP arrays (padded with an extra row and column of zeros) to simplify boundary handling, avoiding special cases for the first row and column.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-09-04 08:50 UTC
- Runtime: 44 ms
- Memory: 29 MB
- Language: C++
