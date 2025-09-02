# Shortest Bridge

**Difficulty:** Medium
**Tags:** depth-first-search, breadth-first-search, matrix, graph-traversal, multi-source-bfs

## Problem

Given an n×n binary grid with exactly two separate islands (connected groups of 1s), find the minimum number of 0s that must be flipped to 1s to connect the two islands. The grid has dimensions between 2×100 and connectivity is measured in 4 directions (up, down, left, right).

## Approach

The solution uses a two-phase approach combining DFS and BFS:

1. **Island Identification**: Use DFS to find and mark the first island. Starting from the first cell containing a 1, recursively visit all connected land cells, marking them with value 2 to distinguish them from the second island. All cells of the first island are collected into a queue.

2. **Multi-source BFS**: Treat all cells of the first island as starting points for a simultaneous BFS expansion. In each iteration, explore all neighbors of the current layer. Water cells (0s) are marked as visited (changed to 2) and added to the next layer. The BFS continues layer by layer, counting steps.

3. **Termination**: When any cell in the expanding frontier encounters a cell with value 1 (part of the second island), return the current step count, which represents the minimum bridge length needed.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2025-09-02 07:21 UTC
- Runtime: 10 ms
- Memory: 24.6 MB
- Language: C++
