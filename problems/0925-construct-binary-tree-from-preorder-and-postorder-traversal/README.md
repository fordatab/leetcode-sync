# Construct Binary Tree from Preorder and Postorder Traversal

**Difficulty:** Medium
**Tags:** binary-tree, recursion, tree-construction, divide-and-conquer

## Problem

Given two arrays representing the preorder and postorder traversals of a binary tree with unique node values, reconstruct and return the original tree. The arrays have equal length (1 to 30 elements), and multiple valid trees may exist for the same traversal pair, so any correct reconstruction is acceptable.

## Approach

The solution uses recursive divide-and-conquer to rebuild the tree. At each step, it identifies the root from the first element of the current preorder range. To partition the tree into left and right subtrees, it finds the left child (second element in preorder) and locates it in the postorder array by linear search, counting how many nodes belong to the left subtree. This count determines where to split both traversal arrays. The function then recursively constructs the left subtree using the appropriate ranges in both arrays, followed by the right subtree with the remaining ranges. Base cases handle single nodes and empty ranges directly.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2026-05-05 04:37 UTC
- Runtime: 0 ms
- Memory: 28.3 MB
- Language: C++
