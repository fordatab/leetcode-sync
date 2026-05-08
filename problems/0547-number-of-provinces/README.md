# Number of Provinces

**Difficulty:** Medium
**Tags:** depth-first-search, graph, connected-components, adjacency-matrix

## Problem

Given n cities represented by an n×n adjacency matrix where isConnected[i][j] = 1 indicates a direct connection between cities i and j, count the number of provinces (connected components). Cities are transitively connected: if A connects to B and B connects to C, then A is indirectly connected to C. The matrix is symmetric with all diagonal elements equal to 1, and n can be up to 200.

## Approach

The solution uses depth-first search (DFS) to find connected components in the graph. It maintains a boolean visited array to track which cities have been explored. For each unvisited city, it increments a counter and performs a DFS that marks all cities reachable from that starting city as visited. The DFS function recursively explores neighbors by checking each row in the adjacency matrix: if isConnected[node][i] is 1 and city i hasn't been visited, it recursively visits city i. After iterating through all cities, the counter represents the total number of disconnected components (provinces).

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2026-05-08 20:23 UTC
- Runtime: 0 ms
- Memory: 19.2 MB
- Language: C++
