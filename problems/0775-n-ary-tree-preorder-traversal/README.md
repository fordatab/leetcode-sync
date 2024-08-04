# N-ary Tree Preorder Traversal

**Difficulty:** Easy
**Tags:** tree, depth-first-search, recursion, n-ary-tree

## Problem

Given the root of an n-ary tree where each node can have any number of children, return the values of all nodes visited in preorder (root before children). The tree can have up to 10,000 nodes with values from 0 to 10,000, and a maximum height of 1000.

## Approach

This solution uses recursive depth-first search to perform preorder traversal. The main function `preorder` initializes an output vector and calls a helper function `dfs` that does the actual work.

The `dfs` function follows the classic preorder pattern: first it checks for a null node (base case), then it adds the current node's value to the result vector, and finally it recursively visits each child in the children vector from left to right.

The recursion naturally handles the traversal order — each node is processed before any of its descendants, which is the definition of preorder traversal. The result vector is passed by reference to avoid copying and to accumulate results across all recursive calls.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-04 05:24 UTC
- Runtime: 13 ms
- Memory: 15.3 MB
- Language: C++
