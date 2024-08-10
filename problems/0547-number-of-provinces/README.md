# Number of Provinces

**Difficulty:** Medium
**Tags:** union-find, graph, connected-components, disjoint-set

## Problem

Given n cities and an n×n adjacency matrix where isConnected[i][j] = 1 indicates cities i and j are directly connected, count the number of provinces (connected components). Cities are transitively connected: if A connects to B and B connects to C, then A and C are in the same province. The matrix is symmetric with 1s on the diagonal, and n can be up to 200.

## Approach

The solution uses Union-Find (Disjoint Set Union) to identify connected components. It initializes each city as its own parent with rank 1. Then it iterates through all entries in the adjacency matrix; whenever isConnected[i][j] is 1, it attempts to union cities i and j. The `doFind` function locates the root parent of a node using path compression (by making each node point to its grandparent during traversal). The `doUnion` function merges two sets by comparing their ranks: the root with smaller rank becomes a child of the root with larger rank, and the ranks are updated accordingly. The result starts at n (assuming all cities are separate provinces) and decrements by 1 each time a successful union merges two previously distinct components. The final count represents the number of disjoint provinces.

## Complexity

- **Time:** O(n^2 * α(n))
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 00:38 UTC
- Runtime: 11 ms
- Memory: 18.5 MB
- Language: C++
