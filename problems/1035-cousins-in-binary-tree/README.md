# Cousins in Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, tree-traversal, string

## Problem

Given a binary tree with unique node values and two distinct target values x and y, determine whether the nodes with these values are cousins. Two nodes are cousins if they exist at the same depth in the tree but have different parent nodes. The tree has between 2 and 100 nodes, and both target values are guaranteed to exist in the tree.

## Approach

The solution uses depth-first search to encode the path from root to each target node as a string. For each node visited during DFS, a '0' is appended to the path string when traversing left and a '1' when traversing right. The path strings are built incrementally and backtracked using push_back and pop_back operations.

Once both paths are found, the solution compares their lengths to verify both nodes are at the same depth. Then it removes the last character from each path (representing the final turn from parent to child) and compares the resulting strings. If the truncated paths are different, the nodes have different parents; if they're the same length and different parents, the nodes are cousins.

The key insight is that path length directly corresponds to depth, and the path with the last character removed represents the path to the parent node. If two nodes at the same depth have different parent paths, they must be cousins.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-06 02:22 UTC
- Runtime: 3 ms
- Memory: 13.1 MB
- Language: C++
