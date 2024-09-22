# Transpose Matrix

**Difficulty:** Easy
**Tags:** matrix, array, simulation

## Problem

Given a 2D integer array with dimensions m×n (where 1 ≤ m, n ≤ 1000 and the total elements don't exceed 10^5), return its transpose by swapping row and column indices. The transpose flips the matrix over its main diagonal, so element at position (i, j) moves to position (j, i).

## Approach

The solution allocates a new result matrix with swapped dimensions (N rows and M columns, where the input has M rows and N columns). It then uses nested loops to iterate through each column index j and row index i of the original matrix, copying element A[i][j] to position B[j][i] in the result matrix. This direct element-by-element copying approach effectively swaps rows with columns. The outer loop iterates over columns of the original matrix (which become rows in the transpose), and the inner loop iterates over rows of the original matrix (which become columns in the transpose).

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-09-22 06:05 UTC
- Runtime: 7 ms
- Memory: 14 MB
- Language: C++
