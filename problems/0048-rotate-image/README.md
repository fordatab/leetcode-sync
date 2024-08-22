# Rotate Image

**Difficulty:** Medium
**Tags:** matrix, array, in-place, transpose

## Problem

Given a square n×n matrix, rotate it 90 degrees clockwise without allocating additional space for another matrix. The rotation must be performed in-place by modifying the input directly. The matrix size ranges from 1 to 20, and element values range from -1000 to 1000.

## Approach

The solution performs a two-step transformation to achieve a 90-degree clockwise rotation:

1. **Reverse the rows**: The matrix rows are reversed from top to bottom using `reverse(matrix.begin(), matrix.end())`. This flips the matrix vertically.

2. **Transpose the matrix**: After reversing, the code iterates through the upper triangle of the matrix (where `j > i`) and swaps elements across the main diagonal, effectively transposing the matrix.

These two operations combined produce a 90-degree clockwise rotation. The key insight is that reversing rows followed by transposing is mathematically equivalent to a clockwise rotation, and both operations can be done in-place with O(1) extra space.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 08:38 UTC
- Runtime: 0 ms
- Memory: 9 MB
- Language: C++
