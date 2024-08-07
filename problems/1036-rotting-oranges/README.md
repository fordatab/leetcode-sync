# Rotting Oranges

**Difficulty:** Medium
**Tags:** breadth-first-search, multi-source-bfs, matrix, queue, simulation

## Problem

Given an m×n grid where cells contain 0 (empty), 1 (fresh orange), or 2 (rotten orange), determine the minimum time in minutes for all fresh oranges to rot, where rot spreads to 4-directionally adjacent fresh oranges each minute. If any fresh orange cannot be reached by rot, return -1. Grid dimensions are at most 10×10.

## Approach

The solution uses a multi-source breadth-first search (BFS) to simulate the rotting process level by level. It begins by scanning the entire grid to enqueue all initially rotten oranges and count the total fresh oranges (`t`). Then it processes the queue in rounds: each round represents one minute, where all oranges that became rotten in the previous minute spread rot to their 4-directional neighbors. For each rotten orange dequeued, the code checks all four adjacent cells; if a neighbor contains a fresh orange, it marks it as rotten (by setting it to 2), decrements the fresh count, and adds it to the queue for the next round. The process continues until either all fresh oranges are rotten (`t` becomes 0) or the queue is exhausted. Finally, it returns the elapsed time if all oranges rotted, or -1 if fresh oranges remain unreachable.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-07 02:37 UTC
- Runtime: 7 ms
- Memory: 16 MB
- Language: C++
