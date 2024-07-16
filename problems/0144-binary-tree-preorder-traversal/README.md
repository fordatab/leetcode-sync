# Binary Tree Preorder Traversal

**Difficulty:** Easy
**Tags:** tree, binary-tree, recursion, depth-first-search, preorder-traversal

## Problem

Given a binary tree's root node, produce a list of all node values in preorder sequence (root, then left subtree, then right subtree). The tree can contain 0 to 100 nodes with values between -100 and 100, and may be empty.

## Approach

This solution uses a recursive approach to perform the preorder traversal. At each node, it first adds the current node's value to the output vector, then recursively traverses the left subtree and appends all values from that traversal, and finally recursively traverses the right subtree and appends those values. The base case checks if the root is null and returns an empty vector. The recursion naturally follows the preorder pattern: process the current node, then recur on the left child, then recur on the right child. Range-based for loops are used to concatenate the results from each recursive call into the output vector.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-16 05:48 UTC
- Runtime: 0 ms
- Memory: 11.5 MB
- Language: C++
