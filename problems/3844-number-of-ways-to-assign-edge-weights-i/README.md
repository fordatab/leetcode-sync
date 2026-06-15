# Number of Ways to Assign Edge Weights I

**Difficulty:** Medium
**Tags:** tree, depth-first-search, combinatorics, modular-exponentiation, graph

## Problem

Given an undirected tree with n nodes rooted at node 1, you must assign each edge a weight of either 1 or 2. The task is to find a node x at maximum depth from the root, then count how many ways the edges along the path from node 1 to x can be weighted such that the total path cost is odd. The tree has n-1 edges, with n ranging up to 10^5, and the answer should be returned modulo 10^9 + 7.

## Approach

The solution uses depth-first search to find the maximum depth of the tree from the root (node 1). The `dfs` function recursively traverses the tree, tracking parent nodes to avoid cycles, and returns the depth by taking the maximum depth among all children plus one.

Once the maximum depth is determined, the solution recognizes that a path from root to a deepest node contains (depth - 1) edges. For the sum of these edge weights to be odd, an odd number of edges must have weight 1 (the rest weight 2).

The key insight is that for a path with k edges, there are 2^(k-1) ways to assign weights such that the sum is odd (half of all 2^k possible assignments yield odd sums). Since the path has (max_depth - 1) edges, the answer is 2^(max_depth - 2).

The `power` function implements modular exponentiation using the binary exponentiation algorithm to efficiently compute 2^(max_depth - 2) mod (10^9 + 7).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-06-15 00:36 UTC
- Runtime: 432 ms
- Memory: 367 MB
- Language: C++
