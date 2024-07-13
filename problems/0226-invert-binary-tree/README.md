# Invert Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, recursion, depth-first-search, tree-traversal

## Problem

Given a binary tree's root node, flip the tree horizontally such that every node's left and right children are swapped, then return the modified root. The tree can have 0 to 100 nodes with values between -100 and 100.

## Approach

This solution uses a recursive depth-first traversal to invert the tree. At each node, it first checks if the node is null (base case), returning nullptr if so. For non-null nodes, it swaps the left and right child pointers by storing the left child in a temporary variable, assigning the right child to left, and the temporary to right. After swapping the children at the current node, it recursively inverts both the left and right subtrees. Finally, it returns the root pointer, which now points to the inverted tree. The recursion naturally handles all nodes in the tree, performing the swap operation from the root down to the leaves.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-13 01:12 UTC
- Runtime: 0 ms
- Memory: 11.8 MB
- Language: C++
