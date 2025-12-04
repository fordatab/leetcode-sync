# Longest Univalue Path

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Find the longest path in a binary tree where all nodes along the path have identical values. The path is measured in edges (not nodes) and can exist anywhere in the tree, not necessarily passing through the root. The tree can have up to 10,000 nodes with values ranging from -1000 to 1000, and a maximum depth of 1000.

## Approach

The solution uses a recursive depth-first search (DFS) that computes two things at each node: the longest single-branch univalue path extending downward from that node, and updates a global maximum considering paths that pass through the current node.

At each node, the algorithm recursively processes both children to get their best downward paths. It then checks if the left child exists and has the same value as the current node; if so, it extends the left path by one edge. The same check is performed for the right child.

The key insight is separating two concepts: (1) a path *through* the current node (sum of left and right extensions), which updates the global maximum, and (2) the best *single branch* downward from the current node (max of left or right extension), which is returned to the parent for potential further extension.

The global maximum is maintained via a reference parameter `out` that accumulates the best result seen across all nodes. The base case returns 0 for null nodes, representing zero edges.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2025-12-04 02:18 UTC
- Runtime: 0 ms
- Memory: 72.2 MB
- Language: C++
