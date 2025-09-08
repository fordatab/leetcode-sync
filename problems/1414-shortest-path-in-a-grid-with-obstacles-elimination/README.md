# Shortest Path in a Grid with Obstacles Elimination

**Difficulty:** Hard
**Tags:** breadth-first-search, graph, shortest-path, grid, state-space-search

## Problem

Given an m×n grid where cells contain either 0 (empty) or 1 (obstacle), find the minimum number of steps to reach from the top-left corner (0,0) to the bottom-right corner (m-1,n-1), moving only up/down/left/right. You can eliminate at most k obstacles during traversal. If no valid path exists, return -1. Both the start and end cells are guaranteed to be empty, and the grid dimensions can be up to 40×40.

## Approach

This solution uses **BFS with state tracking** where each state includes position (x, y) and the count of obstacles broken so far. The key insight is to treat this as a shortest-path problem in a 3D state space: (row, column, obstacles_used).

A 3D distance array `dist[m][n][k+1]` tracks visited states, where `dist[x][y][broken]` indicates whether we've reached cell (x,y) having broken exactly `broken` obstacles. The BFS queue stores tuples of (x, y, broken_count), starting from (0, 0, 0).

For each state, the algorithm explores all four directions. If the next cell is empty and we haven't visited it with the current broken count, we enqueue it with the same broken count. If the next cell is an obstacle, we can only proceed if `broken < k` and we haven't visited that cell with `broken+1` obstacles removed; in this case, we increment the broken counter.

The BFS processes states level-by-level (tracking steps explicitly), ensuring the first time we reach the target cell gives the minimum path length. If the queue empties without reaching the target, we return -1.

## Complexity

- **Time:** O(m * n * k)
- **Space:** O(m * n * k)

## Stats

- Submitted: 2025-09-08 08:56 UTC
- Runtime: 50 ms
- Memory: 36.3 MB
- Language: C++
