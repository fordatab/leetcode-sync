# Minimum Edge Reversals So Every Node Is Reachable

**Difficulty:** Hard
**Tags:** tree, depth-first-search, dynamic-programming, rerooting, graph

## Problem

Given a directed graph with n nodes that would form a tree if edges were bidirectional, compute for each node the minimum number of edge reversals needed so that every other node becomes reachable from it. The graph has exactly n-1 edges, and you must independently determine the answer for each starting node.

## Approach

The solution uses a **rerooting DP technique** with two DFS passes:

1. **First DFS (dfs1)**: Build an undirected graph representation where each edge stores a cost: 0 if traversing in the original direction, 1 if traversing against it (requiring a reversal). Starting from node 0, compute the minimum reversals needed to reach all nodes from node 0 by summing up the costs of edges that need reversal.

2. **Second DFS (dfs2)**: Propagate the answer from parent to child using the rerooting trick. When moving the root from a parent node to a child node, we update the answer by subtracting the cost of the edge from parent to child (since it's no longer traversed in that direction) and adding (1 - cost), which represents the new cost when traversing this edge in the opposite direction.

The key insight is that once we know the answer for one root (node 0), we can efficiently compute answers for all other nodes by adjusting for the cost difference when changing roots, avoiding n separate full traversals.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-24 12:07 UTC
- Runtime: 144 ms
- Memory: 212 MB
- Language: C++
