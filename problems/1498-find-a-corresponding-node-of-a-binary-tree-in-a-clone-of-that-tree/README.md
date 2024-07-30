# Find a Corresponding Node of a Binary Tree in a Clone of That Tree

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given two binary trees where one is an exact clone of the other, and a reference to a specific node in the original tree, find and return the corresponding node in the cloned tree that occupies the same structural position. The tree can have up to 10,000 nodes with unique values, and the target node is guaranteed to exist in the original tree.

## Approach

The solution uses recursive depth-first traversal to simultaneously walk through both trees in parallel. At each step, it checks if the current node in the original tree matches the target node by comparing pointer addresses. When a match is found, it returns the corresponding node from the cloned tree at that same position. If no match at the current node, the function recursively searches the left subtree and then the right subtree of both trees. The search returns the first non-null result found, prioritizing left subtree results over right subtree results. This approach leverages the structural identity between the original and cloned trees, ensuring that when we find the target in the original tree at a certain position, the cloned tree has the corresponding node at exactly the same position.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-30 09:32 UTC
- Runtime: 330 ms
- Memory: 164.2 MB
- Language: C++
