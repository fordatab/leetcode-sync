# Univalued Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree, determine whether all nodes contain the same value. The tree has between 1 and 100 nodes, with node values ranging from 0 to 99. Return true if every node shares the same value, false otherwise.

## Approach

This solution uses a recursive depth-first traversal to verify the uni-valued property. At each node, it checks whether the current node's value matches its immediate children's values (if they exist). If any child has a different value, the function returns false immediately. Otherwise, it recursively validates both the left and right subtrees. The base case handles null nodes by returning true, allowing the recursion to process leaf nodes correctly. The algorithm terminates early when it encounters the first mismatched value, making it efficient for trees that fail the uni-valued property early in the traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-06 02:36 UTC
- Runtime: 0 ms
- Memory: 11.9 MB
- Language: C++
