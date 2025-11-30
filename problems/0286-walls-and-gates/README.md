# Walls and Gates

**Difficulty:** Medium
**Tags:** breadth-first-search, matrix, queue, multi-source-bfs

## Problem

Given an m×n grid where cells contain -1 (walls), 0 (gates), or INT_MAX (empty rooms), modify the grid in-place so each empty room holds the shortest distance to any gate. Rooms unreachable from any gate remain INT_MAX. The grid can be up to 250×250 cells.

## Approach

This solution uses multi-source BFS starting from all gates simultaneously. First, it scans the entire grid to find all cells with value 0 (gates) and adds them to a queue. Then it performs a level-order traversal where each level represents distance from the nearest gate. For each cell dequeued, if it's a gate (value 0) or an empty room (INT_MAX), it assigns the current level as the distance. The algorithm then explores all four adjacent cells, enqueueing any that are empty rooms (INT_MAX). By processing all gates at distance 0 first, then all reachable cells at distance 1, then distance 2, etc., each empty room naturally gets filled with its shortest distance to any gate. Walls (-1) and already-visited cells are never added to the queue.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2025-11-30 05:31 UTC
- Runtime: 3 ms
- Memory: 19.6 MB
- Language: C++
