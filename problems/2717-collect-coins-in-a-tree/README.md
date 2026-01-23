# Collect Coins in a Tree

**Difficulty:** Hard
**Tags:** tree, graph, topological-sort, greedy, bfs

## Problem

Given an undirected tree with n nodes where each node may contain a coin, find the minimum number of edge traversals needed to start at any vertex, collect all coins (which can be collected from up to distance 2 away), and return to the starting vertex. Each edge traversal counts separately, so visiting an edge twice counts as 2.

## Approach

The solution uses a leaf-pruning strategy in three phases:

1. **Remove coinless leaf nodes**: Starting from all leaf nodes (degree 1) that have no coins, iteratively prune them from the tree. When a node is removed, decrement the degrees of its neighbors, which may create new leaves to prune. This eliminates portions of the tree that are unnecessary to visit.

2. **Remove two layers of remaining leaves**: After the first pruning, remove exactly two layers of leaf nodes regardless of whether they have coins. This works because any coin can be collected from distance 2 away, so we don't need to actually traverse to the outermost two layers of the remaining tree—we can collect those coins from two steps away.

3. **Count remaining edges**: After both pruning phases, count how many edges remain in the tree by summing all degrees and dividing by 2. Since we need to traverse each remaining edge twice (once going out, once coming back), multiply by 2 to get the answer.

The key insight is that the optimal path forms a tree structure where we only need to physically visit nodes that are at least 3 steps away from any leaf, since nodes within distance 2 of where we visit can have their coins collected remotely.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-23 02:21 UTC
- Runtime: 138 ms
- Memory: 230.8 MB
- Language: C++
