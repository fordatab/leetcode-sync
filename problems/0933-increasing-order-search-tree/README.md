# Increasing Order Search Tree

**Difficulty:** Easy
**Tags:** binary-search-tree, tree, in-order-traversal, recursion, tree-reconstruction

## Problem

Given a binary search tree, transform it into a right-skewed tree where nodes appear in ascending order. The result should have the smallest value as the new root, with each node having no left child and only a right child, forming a linked-list-like structure. The tree can have 1 to 100 nodes with values ranging from 0 to 1000.

## Approach

The solution performs an in-order traversal of the BST, which naturally visits nodes in ascending order. During traversal, it maintains two pointers: `newRoot` to track the smallest node (which becomes the new root) and `prev` to track the most recently visited node.

As each node is visited in order, the algorithm:
- Links the current node as the right child of the previous node
- Sets the current node's left pointer to null (removing left connections)
- Updates `prev` to point to the current node for the next iteration

When visiting the first node (leftmost/smallest), it's captured as `newRoot` since `prev` is still null. The recursive in-order traversal ensures all nodes are processed left-subtree-first, then current node, then right-subtree, building the right-skewed tree incrementally.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-09-11 23:04 UTC
- Runtime: 5 ms
- Memory: 10.3 MB
- Language: C++
