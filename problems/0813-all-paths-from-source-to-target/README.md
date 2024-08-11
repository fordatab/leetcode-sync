# All Paths From Source to Target

**Difficulty:** Medium
**Tags:** depth-first-search, backtracking, graph, recursion

## Problem

Given a directed acyclic graph with n nodes (labeled 0 to n-1) represented as an adjacency list, find all possible paths from node 0 to node n-1. The graph has at most 15 nodes, contains no self-loops, and is guaranteed to be acyclic. Each node's adjacency list contains unique neighbors.

## Approach

The solution uses depth-first search (DFS) with backtracking to enumerate all paths from the source to the target. Starting at node 0, it maintains a current path vector that tracks the nodes visited so far. At each node, it adds the node to the path, checks if it has reached the target (node n-1), and if so, records the complete path. Otherwise, it recursively explores all neighboring nodes. After exploring all neighbors from a node, it backtracks by removing the node from the current path, allowing the same path vector to be reused for exploring different branches. The solution also maintains a visited array, though it's not strictly necessary since the graph is acyclic and the problem allows revisiting nodes in different paths.

## Complexity

- **Time:** O(2^n * n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-11 19:40 UTC
- Runtime: 11 ms
- Memory: 13.3 MB
- Language: C++
