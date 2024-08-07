# Surrounded Regions

**Difficulty:** Medium
**Tags:** depth-first-search, matrix, graph-traversal, flood-fill

## Problem

Given an m×n grid containing 'X' and 'O' characters, identify all 'O' regions that are completely surrounded by 'X' cells (not touching any board edge) and flip them to 'X'. A region is a connected group of 'O' cells (horizontally or vertically adjacent). The grid dimensions can be up to 200×200, and modifications must be done in-place.

## Approach

The solution uses depth-first search (DFS) to explore each unvisited 'O' cell and determine whether its connected region touches the board edge. For each 'O' cell, it launches a DFS that:

- Marks cells as visited and stores their coordinates (encoded as `x*n + y`) in an unordered set
- Checks all four directions: if any neighbor is out of bounds, the region touches the edge and returns false
- If a neighbor is on the edge (row/column 0 or m-1/n-1) and is 'O', marks the region as non-capturable
- Recursively explores unvisited 'O' neighbors, combining results with a boolean AND operation

After each DFS completes, if the region is fully surrounded (DFS returned true), it decodes all stored coordinates and flips those cells to 'X'. The visited array prevents re-processing cells, and the coordinate set is cleared between regions.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-07 10:14 UTC
- Runtime: 187 ms
- Memory: 38.7 MB
- Language: C++
