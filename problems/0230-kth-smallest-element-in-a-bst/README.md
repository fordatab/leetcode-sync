# Kth Smallest Element in a BST

**Difficulty:** Medium
**Tags:** binary-search-tree, tree, stack, in-order-traversal, iterative

## Problem

Given a binary search tree and an integer k, find the kth smallest value among all node values in the tree, where k is 1-indexed. The tree contains between 1 and 10,000 nodes, node values range from 0 to 10,000, and k is guaranteed to be valid (between 1 and the total number of nodes).

## Approach

The solution performs an iterative in-order traversal of the BST using an explicit stack. It starts at the root and repeatedly pushes nodes onto the stack while moving to the left child, going as far left as possible. Then it pops a node from the stack, increments a counter, and checks if this is the kth node visited. If so, it returns that node's value. Otherwise, it moves to the right child and continues the process.

The key insight is that in-order traversal of a BST visits nodes in ascending order of their values. By counting nodes as they're visited during this traversal, the kth node encountered will have the kth smallest value.

The stack tracks the path from the root down to the current position, allowing the algorithm to backtrack after visiting the leftmost nodes and then explore right subtrees in the correct order.

## Complexity

- **Time:** O(h + k)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-18 03:58 UTC
- Runtime: 16 ms
- Memory: 22.8 MB
- Language: C++
