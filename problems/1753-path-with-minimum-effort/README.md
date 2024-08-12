# Path With Minimum Effort

**Difficulty:** Medium
**Tags:** dijkstra, priority-queue, graph, shortest-path, heap

## Problem

Given a 2D grid of heights, find a path from the top-left corner to the bottom-right corner that minimizes the maximum absolute height difference between any two consecutive cells along the path. You can move in four directions (up, down, left, right), and the grid dimensions can be up to 100×100 with height values up to 10^6.

## Approach

This solution uses Dijkstra's algorithm with a min-heap priority queue to find the path with minimum effort. Each state in the priority queue contains three values: the maximum effort encountered so far on the current path, and the current cell coordinates.

The algorithm starts from the top-left cell (0,0) with effort 0. For each cell visited, it explores all four neighboring cells. When moving to a neighbor, the new effort is calculated as the maximum of: (1) the effort to reach the current cell, and (2) the absolute height difference between the current cell and the neighbor.

A visited array prevents reprocessing cells. The key insight is that once a cell is popped from the priority queue (which guarantees it has the minimum effort to reach that cell), we don't need to visit it again. The algorithm terminates when the bottom-right cell is popped from the queue, returning the associated effort value.

The priority queue ensures cells are processed in order of increasing effort, guaranteeing that the first time we reach the destination, we've found the optimal path.

## Complexity

- **Time:** O(n*m*log(n*m))
- **Space:** O(n*m)

## Stats

- Submitted: 2024-08-12 00:33 UTC
- Runtime: 125 ms
- Memory: 24.7 MB
- Language: C++
