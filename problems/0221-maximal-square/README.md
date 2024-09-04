# Maximal Square

**Difficulty:** Medium
**Tags:** dynamic-programming, matrix, two-dimensional-dp

## Problem

Given a binary matrix of dimensions m×n containing '0's and '1's, find the side length of the largest square submatrix that contains only '1's, then return its area. The matrix dimensions can be up to 300×300, and each cell is guaranteed to be either '0' or '1'.

## Approach

This solution uses dynamic programming with a 2D table where `dp[i][j]` represents the side length of the largest square whose bottom-right corner is at position `(i-1, j-1)` in the original matrix. The DP table is sized `(m+1) × (n+1)` to avoid boundary checks.

For each cell containing '1' in the original matrix, the solution computes the maximum square side length ending at that position by taking the minimum of three neighboring DP values (left, top, and top-left diagonal) and adding 1. This works because a square can only extend by one unit if all three adjacent smaller squares exist.

The algorithm tracks the maximum side length seen across all cells and finally returns the area by squaring this maximum value.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-09-04 05:02 UTC
- Runtime: 70 ms
- Memory: 24.8 MB
- Language: C++
