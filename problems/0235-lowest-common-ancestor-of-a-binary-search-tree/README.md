# Lowest Common Ancestor of a Binary Search Tree

**Difficulty:** Medium
**Tags:** binary-search-tree, tree, recursion, lowest-common-ancestor

## Problem

Given a binary search tree and two distinct nodes within it, identify the lowest common ancestor of those two nodes. The tree contains between 2 and 100,000 nodes with unique values ranging from -10^9 to 10^9, and both target nodes are guaranteed to exist in the tree. A node can be considered its own descendant.

## Approach

The solution exploits the BST property where all left subtree values are smaller and all right subtree values are larger than the current node. Starting from the root, it recursively navigates the tree based on comparing both target node values with the current node's value.

If both target nodes have values greater than the current node, the LCA must be in the right subtree, so the function recurses right. If both values are smaller, it recurses left. Otherwise, when the paths to the two nodes diverge (one goes left, one goes right) or one of the targets equals the current node, the current node is the lowest common ancestor.

This works because in a BST, the first node encountered where the two target values split into different subtrees (or where one target is the node itself) is necessarily their lowest common ancestor.

## Complexity

- **Time:** O(h)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-16 23:30 UTC
- Runtime: 25 ms
- Memory: 22 MB
- Language: C++
