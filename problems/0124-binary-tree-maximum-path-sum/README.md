# Binary Tree Maximum Path Sum

**Difficulty:** Hard
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree, find the maximum sum among all possible paths, where a path is any sequence of connected nodes (not necessarily including the root). Each node may appear at most once in a path. The tree can have up to 30,000 nodes, and node values range from -1000 to 1000, meaning negative values are possible.

## Approach

The solution uses a recursive depth-first search (DFS) that tracks two different values at each node. For every node, it computes the maximum path sum that extends downward through its left and right subtrees (treating negative contributions as zero to handle negative values). At each node, it considers a "bridge" path that goes through the current node connecting its left and right subtrees, updating a global maximum with this value. However, when returning up the recursion, it only returns the maximum single-branch path (current node plus the better of left or right), since a path continuing upward can only follow one branch. The global maximum is passed by reference and updated throughout the traversal, ultimately containing the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-19 23:58 UTC
- Runtime: 25 ms
- Memory: 26.5 MB
- Language: C++
