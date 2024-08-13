# Matrix Diagonal Sum

**Difficulty:** Easy
**Tags:** array, matrix, math

## Problem

Given an n×n square matrix, compute the sum of elements along both diagonals (primary diagonal from top-left to bottom-right, and secondary diagonal from top-right to bottom-left). Elements that appear on both diagonals should only be counted once. The matrix has dimensions between 1×1 and 100×100, with element values ranging from 1 to 100.

## Approach

The solution uses two sequential passes through the matrix diagonals:

1. **First pass (primary diagonal)**: Starting at position (0,0), traverse diagonally by incrementing both row and column indices simultaneously until reaching the bottom-right corner, accumulating the sum of all elements along this diagonal.

2. **Second pass (secondary diagonal)**: Starting at position (0, n-1), traverse diagonally by incrementing the row index while decrementing the column index until reaching the bottom-left corner, adding these elements to the running sum.

3. **Duplicate correction**: For matrices with odd dimensions, the center element at position (n/2, n/2) lies on both diagonals and gets counted twice during the two passes. The solution detects this using modulo arithmetic and subtracts the center element once to correct the overcount.

This straightforward approach avoids complex indexing logic by treating each diagonal as a simple linear traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-13 23:26 UTC
- Runtime: 11 ms
- Memory: 14.2 MB
- Language: C++
