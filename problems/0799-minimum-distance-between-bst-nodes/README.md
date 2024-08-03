# Minimum Distance Between BST Nodes

**Difficulty:** Easy
**Tags:** binary-search-tree, tree-traversal, in-order-traversal, recursion, depth-first-search

## Problem

Given a binary search tree with 2 to 100 nodes where node values range from 0 to 10⁵, find the smallest absolute difference between the values of any two distinct nodes in the tree. The tree structure guarantees that for every node, all values in its left subtree are smaller and all values in its right subtree are larger.

## Approach

The solution performs an in-order traversal of the BST, which visits nodes in ascending order of their values. It maintains a pointer to the previously visited node and tracks the minimum difference found so far.

During the traversal, after visiting the left subtree and before visiting the right subtree, the code compares the current node's value with the previous node's value (if one exists). Since in-order traversal guarantees that consecutive nodes in the traversal are consecutive in sorted order, the minimum difference must occur between some pair of adjacent nodes in this sequence.

The algorithm uses recursion to traverse left, process the current node, then traverse right. The `prev` pointer is passed by reference so updates persist across recursive calls, allowing each node to compare itself with its in-order predecessor. The minimum difference `m` is also passed by reference and updated whenever a smaller difference is found.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-03 09:30 UTC
- Runtime: 0 ms
- Memory: 11.5 MB
- Language: C++
