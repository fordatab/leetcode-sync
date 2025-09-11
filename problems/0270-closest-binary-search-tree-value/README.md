# Closest Binary Search Tree Value

**Difficulty:** Easy
**Tags:** binary-search-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary search tree and a target floating-point value, find the node value in the tree that has the minimum absolute difference from the target. When multiple values are equally close to the target, return the smallest one. The tree can contain up to 10,000 nodes with values ranging from 0 to 10^9, and the target can range from -10^9 to 10^9.

## Approach

The solution uses a depth-first search to traverse the entire BST while maintaining a reference to the closest value found so far. Starting with the root's value as the initial closest candidate, it recursively visits all nodes in the tree.

At each node, it compares the absolute difference between the current node's value and the target against the current closest value. If the current node is closer, it updates the closest value. When two values have equal distance from the target, it selects the smaller value to satisfy the tie-breaking requirement.

The algorithm explores both left and right subtrees for every node, effectively performing a complete tree traversal. While it doesn't leverage the BST property to prune the search space, it correctly examines all nodes to guarantee finding the globally closest value.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2025-09-11 09:27 UTC
- Runtime: 0 ms
- Memory: 21.3 MB
- Language: C++
