# Largest Local Values in a Matrix

**Difficulty:** Easy
**Tags:** matrix, sliding-window, nested-loops, array

## Problem

Given an n×n integer matrix, generate an (n-2)×(n-2) result matrix where each cell contains the maximum value from the corresponding 3×3 submatrix in the input. Each result cell at position (i,j) represents the maximum of the 3×3 window centered at (i+1,j+1) in the original grid. The input size ranges from 3 to 100, and all values are between 1 and 100.

## Approach

The solution uses a straightforward sliding window approach with nested loops. It iterates through all valid center positions (from index 1 to n-2) in both dimensions, which correspond to positions where a 3×3 window can be centered. For each center position (x,y), it examines all 9 cells in the 3×3 neighborhood using two inner loops that scan from (x-1,y-1) to (x+1,y+1). During this scan, it tracks the maximum value encountered and stores it in the output matrix at the appropriate position (x-1,y-1), which maps the center coordinates to the result matrix's indexing scheme. The solution directly computes each result cell independently without any optimization for overlapping windows.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-21 07:17 UTC
- Runtime: 16 ms
- Memory: 13.8 MB
- Language: C++
