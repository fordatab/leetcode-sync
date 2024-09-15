# Construct Binary Tree from Inorder and Postorder Traversal

**Difficulty:** Medium
**Tags:** binary-tree, tree-construction, divide-and-conquer, recursion, array

## Problem

Given two arrays representing the inorder and postorder traversals of a binary tree with unique values, reconstruct and return the original tree. The arrays have equal length between 1 and 3000 elements, with values ranging from -3000 to 3000, and every value in the postorder array appears in the inorder array.

## Approach

The solution uses a recursive divide-and-conquer approach. In postorder traversal, the last element is always the root of the (sub)tree. The algorithm takes the last element of the current postorder range as the root, then locates this value in the inorder array by linear search. This position divides the inorder array into left and right subtrees. Since inorder visits left subtree, root, then right subtree, everything before the root position belongs to the left subtree and everything after belongs to the right subtree. The algorithm recursively builds the left and right subtrees by calculating the corresponding ranges in both arrays. The left subtree in the postorder array starts at the same offset as in the inorder array, and the right subtree occupies the remaining elements before the root. The recursion terminates when the range boundaries cross, returning nullptr for empty subtrees.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-15 04:42 UTC
- Runtime: 13 ms
- Memory: 26.8 MB
- Language: C++
