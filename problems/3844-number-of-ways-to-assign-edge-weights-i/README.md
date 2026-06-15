# Number of Ways to Assign Edge Weights I

**Difficulty:** Medium
**Tags:** tree, depth-first-search, graph, combinatorics, modular-exponentiation

## Problem

Given an undirected tree with n nodes rooted at node 1, assign each edge a weight of either 1 or 2. Find a node at maximum depth from the root, then count how many ways the edges on the path from node 1 to that deepest node can be weighted such that the total path cost is odd. Return the count modulo 10^9 + 7.

## Approach

The solution first builds an adjacency list representation of the tree from the edge list. It then performs a depth-first search (DFS) starting from node 1 to calculate the maximum depth of the tree, where depth is measured as the number of edges from the root to the furthest leaf.

The key insight is that for a path with k edges, we need an odd number of edges with weight 1 (and the rest with weight 2) to achieve an odd total cost. For k edges, there are 2^(k-1) ways to assign weights that result in an odd sum: we can choose any subset of odd size from the k edges to have weight 1.

Since the maximum depth represents the number of edges in the longest root-to-leaf path, and this value is stored as `max_depth`, the solution computes 2^(max_depth - 2) using modular exponentiation. The formula uses (max_depth - 2) because the DFS counts nodes rather than edges, so the actual number of edges is (max_depth - 1), and half of the 2^(max_depth - 1) total assignments yield odd sums, giving 2^(max_depth - 2).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-06-15 00:36 UTC
- Runtime: 432 ms
- Memory: 367 MB
- Language: C++
