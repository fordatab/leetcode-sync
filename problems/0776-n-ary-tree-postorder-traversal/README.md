# N-ary Tree Postorder Traversal

**Difficulty:** Easy
**Tags:** tree, n-ary-tree, recursion, depth-first-search, postorder-traversal

## Problem

Given the root of an n-ary tree where each node can have any number of children, return the values of all nodes in postorder traversal order. The tree can have up to 10,000 nodes with values between 0 and 10,000, and a maximum height of 1000.

## Approach

This solution uses a recursive approach to perform postorder traversal. The main function `postorder` initializes an empty result vector and calls the helper function `post_order`. The helper function implements the classic postorder pattern: it first checks if the current node is null (base case), then recursively visits all children nodes by iterating through the `children` vector, and finally appends the current node's value to the result vector. This ensures that all descendants are processed before the parent node, which is the defining characteristic of postorder traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-01 04:13 UTC
- Runtime: 13 ms
- Memory: 15.2 MB
- Language: C++
