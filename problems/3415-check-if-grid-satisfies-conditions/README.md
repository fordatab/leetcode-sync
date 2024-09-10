# Check if Grid Satisfies Conditions

**Difficulty:** Easy
**Tags:** matrix, array, simulation

## Problem

Given an m×n grid of integers, determine whether every cell satisfies two conditions: each cell must equal the cell directly below it (if one exists), and must differ from the cell immediately to its right (if one exists). The grid dimensions are small (at most 10×10) and cell values range from 0 to 9.

## Approach

The solution uses two separate passes through the grid to validate both conditions independently.

In the first pass, it iterates through all rows except the last one, checking that each cell equals the cell directly below it. If any vertical pair differs, it immediately returns false.

In the second pass, it iterates through all columns except the last one in each row, checking that each cell differs from its right neighbor. If any horizontal pair matches, it returns false.

Only if both passes complete without finding violations does the function return true, confirming that all cells satisfy both required conditions.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 05:25 UTC
- Runtime: 11 ms
- Memory: 28.9 MB
- Language: C++
