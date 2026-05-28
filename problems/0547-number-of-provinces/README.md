# Number of Provinces

**Difficulty:** Medium
<<<<<<< HEAD
**Tags:** union-find, graph, connected-components, disjoint-set

## Problem

Given n cities and an n×n adjacency matrix where isConnected[i][j] = 1 indicates cities i and j are directly connected, count the number of provinces (connected components). Cities are transitively connected: if A connects to B and B connects to C, then A and C are in the same province. The matrix is symmetric with 1s on the diagonal, and n can be up to 200.

## Approach

The solution uses Union-Find (Disjoint Set Union) to identify connected components. It initializes each city as its own parent with rank 1. Then it iterates through all entries in the adjacency matrix; whenever isConnected[i][j] is 1, it attempts to union cities i and j. The `doFind` function locates the root parent of a node using path compression (by making each node point to its grandparent during traversal). The `doUnion` function merges two sets by comparing their ranks: the root with smaller rank becomes a child of the root with larger rank, and the ranks are updated accordingly. The result starts at n (assuming all cities are separate provinces) and decrements by 1 each time a successful union merges two previously distinct components. The final count represents the number of disjoint provinces.

## Complexity

- **Time:** O(n^2 * α(n))
=======
**Tags:** depth-first-search, graph, connected-components, adjacency-matrix

## Problem

Given n cities represented by an n×n adjacency matrix where isConnected[i][j] = 1 indicates a direct connection between cities i and j, count the number of provinces (connected components). Cities are transitively connected: if A connects to B and B connects to C, then A is indirectly connected to C. The matrix is symmetric with all diagonal elements equal to 1, and n can be up to 200.

## Approach

The solution uses depth-first search (DFS) to find connected components in the graph. It maintains a boolean visited array to track which cities have been explored. For each unvisited city, it increments a counter and performs a DFS that marks all cities reachable from that starting city as visited. The DFS function recursively explores neighbors by checking each row in the adjacency matrix: if isConnected[node][i] is 1 and city i hasn't been visited, it recursively visits city i. After iterating through all cities, the counter represents the total number of disconnected components (provinces).

## Complexity

- **Time:** O(n^2)
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- **Space:** O(n)

## Stats

<<<<<<< HEAD
- Submitted: 2024-08-10 00:38 UTC
- Runtime: 11 ms
- Memory: 18.5 MB
=======
- Submitted: 2026-05-08 20:23 UTC
- Runtime: 0 ms
- Memory: 19.2 MB
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
