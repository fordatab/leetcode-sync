# Binary Tree Pruning

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, recursion, post-order-traversal

## Problem

Given a binary tree where each node contains either 0 or 1, remove all subtrees that don't contain at least one node with value 1. The tree has between 1 and 200 nodes. Return the modified tree after pruning.

## Approach

The solution uses a recursive depth-first search (DFS) to traverse the tree in post-order fashion. For each node, it first recursively processes the left and right subtrees, receiving boolean values indicating whether each subtree contains at least one 1. If a child subtree doesn't contain any 1s (returns false), that child pointer is set to null, effectively pruning it. The function then returns true if either the left subtree contains a 1, or the right subtree contains a 1, or the current node's value is 1 — otherwise it returns false. This bottom-up approach ensures that pruning decisions are made with complete information about descendants. The main function wraps this by checking if the entire tree should be pruned (if the root itself should be removed).

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2025-09-11 01:54 UTC
- Runtime: 0 ms
- Memory: 12.5 MB
- Language: C++
