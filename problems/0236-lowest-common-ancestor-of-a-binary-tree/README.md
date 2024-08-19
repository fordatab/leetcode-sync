# Lowest Common Ancestor of a Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, recursion, depth-first-search, tree-traversal

## Problem

Find the deepest node in a binary tree that is an ancestor of two specified nodes. The tree contains between 2 and 100,000 nodes with unique values, and both target nodes are guaranteed to exist. A node can be considered its own descendant.

## Approach

The solution uses a recursive depth-first search that traverses the tree from the root. At each node, it checks three base cases: if the current node is null (return null), if it matches either target node (return that node immediately). Then it recursively searches both the left and right subtrees. The key insight is in the combination logic: if both recursive calls return non-null values, it means one target is in the left subtree and the other is in the right subtree, so the current node must be their lowest common ancestor. If only one subtree returns a non-null value, that value is propagated upward—it represents either a target node found or an already-identified LCA from a deeper level. This bottom-up propagation ensures that the first node where both subtrees report findings is the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-19 03:23 UTC
- Runtime: 13 ms
- Memory: 16.4 MB
- Language: C++
