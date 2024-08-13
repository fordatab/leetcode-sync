# Subrectangle Queries

**Difficulty:** Medium
**Tags:** matrix, array, design, simulation

## Problem

Design a data structure that maintains a 2D integer matrix and supports two operations: updating all values in a specified rectangular region to a new value, and retrieving the current value at a specific cell. The matrix can be up to 100×100, and there will be at most 500 total operations across both methods.

## Approach

The solution uses a straightforward in-place update strategy. The constructor stores the input matrix directly (using swap for efficiency). When `updateSubrectangle` is called, it iterates through all cells within the specified rectangular bounds (from row1 to row2 and col1 to col2) using nested loops, setting each cell to the new value. The `getValue` method simply performs a direct lookup in the stored matrix. This approach prioritizes simplicity and fast queries at the expense of potentially slower updates when large rectangles are modified.

## Complexity

- **Time:** O(1) for getValue, O((row2-row1+1) * (col2-col1+1)) for updateSubrectangle
- **Space:** O(rows * cols)

## Stats

- Submitted: 2024-08-13 23:11 UTC
- Runtime: 28 ms
- Memory: 23.2 MB
- Language: C++
