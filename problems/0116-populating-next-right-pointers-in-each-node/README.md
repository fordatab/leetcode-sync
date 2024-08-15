# Populating Next Right Pointers in Each Node

**Difficulty:** Medium
**Tags:** binary-tree, tree-traversal, level-order-traversal, linked-list, iteration

## Problem

Given a perfect binary tree where all leaves are at the same depth and every internal node has exactly two children, populate each node's 'next' pointer to reference its immediate right neighbor at the same level. Nodes at the end of each level should have their 'next' pointer set to NULL. The tree can contain up to 4095 nodes (2^12 - 1), with node values ranging from -1000 to 1000.

## Approach

The solution uses an iterative level-order traversal approach with O(1) extra space by leveraging the 'next' pointers that have already been established.

Starting from the root, the algorithm processes the tree level by level. For each level, it maintains a `levelStart` pointer to the leftmost node and a `cur` pointer to traverse horizontally across that level using the `next` pointers.

At each node during the horizontal traversal, two connections are made: (1) the left child's `next` is set to the right child, and (2) if the current node has a next neighbor, the right child's `next` is set to that neighbor's left child. This cleverly links children across parent boundaries.

After processing all nodes in the current level, the algorithm descends to the next level by following the `left` pointer from `levelStart`. The process continues until reaching a level with no children (leaf level), at which point all `next` pointers have been populated.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-15 08:39 UTC
- Runtime: 8 ms
- Memory: 18.8 MB
- Language: C++
