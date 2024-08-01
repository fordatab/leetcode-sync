# Balance a Binary Search Tree

**Difficulty:** Medium
**Tags:** binary-search-tree, tree, divide-and-conquer, recursion, inorder-traversal

## Problem

Given a binary search tree that may be unbalanced, transform it into a balanced BST containing the same node values. A BST is considered balanced when every node's left and right subtree heights differ by at most one. The tree can contain between 1 and 10,000 nodes with values from 1 to 100,000.

## Approach

The solution uses a two-phase approach: extraction and reconstruction.

First, it performs an inorder traversal of the original BST to extract all node values into a sorted vector. Since inorder traversal of a BST visits nodes in ascending order, this naturally produces a sorted array.

Second, it reconstructs a balanced BST from the sorted array using a recursive divide-and-conquer strategy. The `create` function repeatedly selects the middle element of the current range as the root, which ensures the left and right subtrees have equal (or nearly equal) sizes. It then recursively builds the left subtree from elements before the middle and the right subtree from elements after the middle.

This middle-selection strategy guarantees balance because at each level, the subtrees differ in size by at most one node, which translates to a height difference of at most one throughout the entire tree.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-01 04:02 UTC
- Runtime: 104 ms
- Memory: 64 MB
- Language: C++
