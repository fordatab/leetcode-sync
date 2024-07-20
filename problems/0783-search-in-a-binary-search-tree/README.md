# Search in a Binary Search Tree

**Difficulty:** Easy
**Tags:** binary-search-tree, recursion, tree-traversal, binary-tree

## Problem

Given the root of a binary search tree and a target integer value, locate the node whose value matches the target and return the entire subtree rooted at that node. If no such node exists, return null. The tree can contain between 1 and 5000 nodes, with node values ranging from 1 to 10^7.

## Approach

This solution uses recursive traversal that exploits the BST property. At each node, it first checks if the current node is null (base case returning nullptr) or if the current node's value matches the target (base case returning the node itself). If neither base case applies, it compares the target value against the current node's value: if the target is smaller, it recursively searches the left subtree; otherwise, it searches the right subtree. The BST ordering property guarantees that values smaller than a node are in its left subtree and larger values are in its right subtree, allowing the algorithm to eliminate half of the remaining tree at each step.

## Complexity

- **Time:** O(h)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-20 07:07 UTC
- Runtime: 37 ms
- Memory: 33.6 MB
- Language: C++
