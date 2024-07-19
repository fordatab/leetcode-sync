# Construct Binary Tree from Preorder and Inorder Traversal

**Difficulty:** Medium
**Tags:** binary-tree, tree-construction, recursion, divide-and-conquer, array

## Problem

Given two arrays representing the preorder and inorder traversals of a binary tree with unique values, reconstruct the original binary tree. Both arrays have the same length (1 to 3000 elements), contain values between -3000 and 3000, and each value in one array appears exactly once in the other. The arrays are guaranteed to be valid traversals of the same tree.

## Approach

The solution uses a recursive divide-and-conquer approach. In each recursive call, the first element of the preorder array is identified as the current subtree's root (since preorder visits the root first). This root value is then located in the inorder array using `std::find`, which divides the inorder array into left and right subtrees (inorder visits left subtree, then root, then right subtree).

The code extracts four new subarrays: `leftPre` and `leftIn` for the left subtree, and `rightPre` and `rightIn` for the right subtree. The sizes are determined by the position of the root in the inorder array. These subarrays are then passed recursively to construct the left and right children.

The base case returns `nullptr` when the input arrays are empty. Each recursive call creates a new `TreeNode` with the appropriate value and connects it to its recursively-built children, eventually returning the fully constructed tree.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n^2)

## Stats

- Submitted: 2024-07-19 19:06 UTC
- Runtime: 12 ms
- Memory: 74 MB
- Language: C++
