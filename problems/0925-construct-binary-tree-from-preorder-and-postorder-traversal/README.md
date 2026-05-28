# Construct Binary Tree from Preorder and Postorder Traversal

**Difficulty:** Medium
<<<<<<< HEAD
**Tags:** binary-tree, recursion, tree-construction, divide-and-conquer, array

## Problem

Given two arrays representing the preorder and postorder traversals of a binary tree with distinct node values, reconstruct and return the original tree. The arrays are guaranteed to represent the same tree, and if multiple valid trees exist, any one may be returned. The tree can have up to 30 nodes with values between 1 and the array length.

## Approach

The solution uses recursive divide-and-conquer to rebuild the tree. For each subtree, it identifies the root from the preorder array (always the first element in the current range). To partition left and right subtrees, it looks at the second element in preorder (which is the left child's root if it exists) and searches for this value in the postorder array to determine how many nodes belong to the left subtree.

Once the left subtree size is known, the solution recursively constructs the left child using the appropriate slice of preorder (starting after the root) and postorder (from the start of the range). The right subtree is built from the remaining elements in both arrays.

Base cases handle empty ranges (returning NULL) and single-node subtrees (creating a leaf node). The key insight is that in preorder, the root comes first followed by its left subtree, while in postorder, the left subtree appears first followed by the right subtree and then the root, allowing us to identify subtree boundaries.
=======
**Tags:** binary-tree, recursion, tree-construction, divide-and-conquer

## Problem

Given two arrays representing the preorder and postorder traversals of a binary tree with unique node values, reconstruct and return the original tree. The arrays have equal length (1 to 30 elements), and multiple valid trees may exist for the same traversal pair, so any correct reconstruction is acceptable.

## Approach

The solution uses recursive divide-and-conquer to rebuild the tree. At each step, it identifies the root from the first element of the current preorder range. To partition the tree into left and right subtrees, it finds the left child (second element in preorder) and locates it in the postorder array by linear search, counting how many nodes belong to the left subtree. This count determines where to split both traversal arrays. The function then recursively constructs the left subtree using the appropriate ranges in both arrays, followed by the right subtree with the remaining ranges. Base cases handle single nodes and empty ranges directly.
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2026-05-05 04:37 UTC
- Runtime: 0 ms
- Memory: 28.3 MB
- Language: C++
