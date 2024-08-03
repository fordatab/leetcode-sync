# Clone Graph

**Difficulty:** Medium
**Tags:** graph, depth-first-search, hash-table, recursion, cloning

## Problem

Given a reference to a node in a connected undirected graph where each node has an integer value and a list of neighbor references, create and return a complete deep copy of the entire graph. The graph can have 0 to 100 nodes, each with a unique value between 1 and 100, with no self-loops or duplicate edges, and all nodes are reachable from the given starting node.

## Approach

The solution uses depth-first search (DFS) with memoization to clone the graph. It maintains a hash map that maps original nodes to their corresponding cloned nodes, preventing infinite recursion in cycles and ensuring each node is cloned exactly once.

When visiting a node, the algorithm first checks if it's null (base case for empty graph) or already cloned (found in the map). If already cloned, it returns the existing clone. Otherwise, it creates a new node with the same value, immediately stores it in the map to handle cycles, then recursively clones all neighbors and adds them to the new node's neighbor list.

The key insight is that by storing the clone in the map before recursing on neighbors, the algorithm naturally handles circular references — when a neighbor's DFS eventually circles back to an already-visited node, the map lookup returns the previously created clone rather than creating duplicates or infinite loops.

## Complexity

- **Time:** O(n + e)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-03 07:24 UTC
- Runtime: 8 ms
- Memory: 12.1 MB
- Language: C++
