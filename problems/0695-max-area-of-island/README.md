# Max Area of Island

**Difficulty:** Medium
**Tags:** depth-first-search, matrix, recursion, graph-traversal, grid

## Problem

Given an m×n binary matrix where 1 represents land and 0 represents water, find the maximum area of any island. Islands are formed by 1s connected horizontally or vertically (4-directional connectivity). The grid dimensions are constrained to 1 ≤ m, n ≤ 50, and if no island exists, return 0.

## Approach

The solution uses depth-first search (DFS) to explore each island. It iterates through every cell in the grid, and when it encounters a land cell (value 1), it initiates a DFS to calculate that island's area.

The DFS function recursively explores all four adjacent cells (up, down, left, right). To avoid counting the same cell multiple times, each visited land cell is marked as water (set to 0) during exploration. The function returns 0 for out-of-bounds positions or water cells, and for land cells, it returns 1 plus the sum of areas from all four neighboring directions.

As each island is fully explored, its total area is compared with the current maximum, and the largest area encountered is tracked. This approach modifies the input grid in-place to mark visited cells, eliminating the need for a separate visited array.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-07-30 06:44 UTC
- Runtime: 15 ms
- Memory: 26.8 MB
- Language: C++
