# Jump Game IV

**Difficulty:** Hard
**Tags:** breadth-first-search, hash-table, graph, shortest-path

## Problem

Given an array of integers, start at index 0 and find the minimum number of jumps to reach the last index. From any position i, you can jump to i+1, i-1, or to any other index j where arr[i] equals arr[j]. The array can have up to 50,000 elements with values ranging from -10^8 to 10^8.

## Approach

This solution uses **breadth-first search (BFS)** to find the shortest path from index 0 to the last index. A hashmap is built mapping each unique value to all indices containing that value, enabling constant-time lookup of teleportation destinations.

The BFS explores positions level by level, where each level represents one additional jump. At each position, three types of moves are considered: moving left (i-1), moving right (i+1), and teleporting to any index with the same value. A visited array prevents revisiting indices.

A key optimization is that after exploring all indices with a particular value, that value is erased from the hashmap. This prevents redundant exploration since if we've already queued all positions with value V from one index, we don't need to queue them again from another index with the same value.

The algorithm terminates when the last index is dequeued, returning the current step count as the minimum number of jumps needed.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-06-15 04:26 UTC
- Runtime: 75 ms
- Memory: 76.9 MB
- Language: C++
