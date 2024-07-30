# Number of Islands

**Difficulty:** Medium
**Tags:** depth-first-search, grid, graph, connected-components

## Problem

Given a 2D grid of m×n cells where each cell contains either '1' (land) or '0' (water), count the number of distinct islands. An island is a group of adjacent land cells connected horizontally or vertically, with all grid edges considered water. The grid dimensions can be up to 300×300.

## Approach

The solution uses depth-first search (DFS) with grid modification to count connected components. It iterates through every cell in the grid, and whenever it finds a land cell ('1'), it increments the island counter and launches a DFS traversal from that cell.

The DFS function marks the current cell as visited by changing it from '1' to '0', then recursively explores all four adjacent cells (up, down, left, right). The base case stops recursion when encountering boundaries or water cells.

By marking visited land cells as water, the algorithm ensures each land cell is counted only once. Each DFS invocation explores an entire connected component, so the number of times DFS is initiated from the main loop equals the total number of islands.

## Complexity

- **Time:** O(m × n)
- **Space:** O(m × n)

## Stats

- Submitted: 2024-07-30 06:34 UTC
- Runtime: 22 ms
- Memory: 16.1 MB
- Language: C++
