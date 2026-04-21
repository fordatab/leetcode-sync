# Find Leaves of Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, post-order-traversal, recursion

## Problem

Given a binary tree, repeatedly collect and remove all leaf nodes until the tree becomes empty, returning the nodes grouped by each removal round. The tree has between 1 and 100 nodes with values ranging from -100 to 100. The order of nodes within each collection round doesn't matter.

## Approach

The solution computes the "height" of each node, defined as the maximum distance to any leaf below it (leaves have height 0, their parents have height 1, etc.). Using a post-order traversal, the algorithm recursively determines each node's height by finding the maximum height of its children and adding 1. Nodes are then grouped by their height into a results vector, where `leaves[h]` contains all nodes at height `h`. This naturally groups nodes that would be removed in the same iteration—all leaves (height 0) are removed first, then their parents (height 1), and so on. The result vector is dynamically expanded as new heights are discovered during the traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 20:25 UTC
- Runtime: 3 ms
- Memory: 11.4 MB
- Language: C++
