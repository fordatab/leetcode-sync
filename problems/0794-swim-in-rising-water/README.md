# Swim in Rising Water

**Difficulty:** Hard
**Tags:** heap, priority-queue, dijkstra, graph, greedy

## Problem

Given an n×n grid where each cell contains a unique elevation value, find the minimum time needed to reach the bottom-right corner from the top-left corner. At time t, you can move between adjacent cells if both cells have elevation at most t. The grid size can be up to 50×50, and elevations range from 0 to n²-1.

## Approach

This solution uses a modified Dijkstra's algorithm with a min-heap priority queue. It treats the problem as finding the path that minimizes the maximum elevation encountered along the way.

The algorithm starts at cell (0,0) and maintains a priority queue ordered by the maximum elevation seen so far on each path. For each cell popped from the queue, it explores all four adjacent neighbors. When visiting a neighbor, the new "cost" is the maximum of the current path's maximum elevation and the neighbor's elevation.

A visited matrix tracks which cells have been processed to avoid revisiting them. The algorithm terminates when it reaches the bottom-right corner (n-1, n-1), returning the maximum elevation encountered on the optimal path, which represents the minimum time needed to make that path traversable.

## Complexity

- **Time:** O(n² log n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-08-12 00:03 UTC
- Runtime: 11 ms
- Memory: 12.6 MB
- Language: C++
