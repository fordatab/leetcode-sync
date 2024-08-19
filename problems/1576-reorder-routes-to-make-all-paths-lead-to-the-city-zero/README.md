# Reorder Routes to Make All Paths Lead to the City Zero

**Difficulty:** Medium
**Tags:** tree, depth-first-search, graph, greedy

## Problem

Given n cities connected by n-1 directed roads forming a tree structure, determine the minimum number of road directions that must be reversed so that all cities can reach city 0. Each road is initially directed from city a to city b, and the graph is guaranteed to be connected as an undirected tree.

## Approach

The solution builds an adjacency list where each edge is stored bidirectionally with a boolean flag indicating whether it's an original directed edge (true) or a reverse edge (false). Starting from city 0, it performs a depth-first search traversal treating the graph as undirected. During the DFS, whenever it follows an edge that was originally directed away from city 0 (marked as true), it increments the counter because that edge needs to be reversed. The visited array prevents revisiting nodes. The total count represents edges pointing in the wrong direction that need reorientation.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-19 05:48 UTC
- Runtime: 420 ms
- Memory: 116.2 MB
- Language: C++
