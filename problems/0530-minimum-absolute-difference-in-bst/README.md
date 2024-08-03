# Minimum Absolute Difference in BST

**Difficulty:** Easy
**Tags:** binary-search-tree, tree-traversal, in-order-traversal, depth-first-search

## Problem

Given a binary search tree, find the smallest absolute difference between values of any two distinct nodes. The tree contains between 2 and 10,000 nodes with values ranging from 0 to 100,000.

## Approach

The solution performs an in-order traversal of the BST, which visits nodes in ascending order of their values. It maintains a pointer to the previously visited node and tracks the minimum difference seen so far.

During the traversal, after visiting the left subtree (which contains smaller values), the code compares the current node's value with the previous node's value. Since in-order traversal processes nodes in sorted order, consecutive nodes in this traversal are candidates for the minimum difference.

The algorithm updates the minimum difference whenever it finds a smaller absolute difference between the current and previous node values. By leveraging the BST property through in-order traversal, it only needs to check adjacent nodes in the sorted sequence rather than all pairs of nodes.

The `prev` pointer is passed by reference and updated after each node is processed, ensuring it always points to the most recently visited node in the in-order sequence.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-03 08:12 UTC
- Runtime: 12 ms
- Memory: 24.1 MB
- Language: C++
