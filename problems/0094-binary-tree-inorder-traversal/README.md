# Binary Tree Inorder Traversal

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree's root node, produce a list of all node values visited in inorder sequence (left subtree, current node, right subtree). The tree may contain 0 to 100 nodes with values between -100 and 100.

## Approach

This solution uses a recursive depth-first search to perform the inorder traversal. The main function `inorderTraversal` initializes an empty result vector and delegates to a helper function `dfs`.

The `dfs` helper function implements the classic inorder traversal pattern:
- It first checks if the current node is null and returns early if so
- Recursively processes the left subtree
- Appends the current node's value to the result vector
- Recursively processes the right subtree

By visiting left children before the current node and right children after, this ordering ensures values appear in the result vector in proper inorder sequence. The result vector is passed by reference to avoid copying overhead during recursion.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 03:58 UTC
- Runtime: 4 ms
- Memory: 10 MB
- Language: C++
