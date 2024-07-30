# Symmetric Tree

**Difficulty:** Easy
**Tags:** binary-tree, recursion, depth-first-search, tree-traversal

## Problem

Given a binary tree's root node, determine whether the tree exhibits mirror symmetry about its vertical center line. The tree has between 1 and 1000 nodes with values ranging from -100 to 100. A tree is symmetric if the left subtree is a mirror reflection of the right subtree in both structure and node values.

## Approach

The solution uses a recursive helper function to compare pairs of nodes that should be mirror images of each other. Starting from the root, it compares the left and right child subtrees by calling the helper with these two nodes.

The helper function checks three base cases: if both nodes are null (symmetric), if only one is null (not symmetric), or if their values differ (not symmetric). When both nodes exist and have equal values, it recursively validates that the left child's left subtree mirrors the right child's right subtree, and that the left child's right subtree mirrors the right child's left subtree.

This cross-comparison pattern—comparing outer branches with outer branches and inner branches with inner branches—ensures that the tree's structure and values are symmetric. The recursion naturally handles all levels of the tree, returning true only when every mirrored pair matches.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-30 00:19 UTC
- Runtime: 0 ms
- Memory: 17.6 MB
- Language: C++
