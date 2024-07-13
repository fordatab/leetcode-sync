# Maximum Depth of Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, recursion, depth-first-search, tree-traversal

## Problem

Given a binary tree's root node, determine the maximum depth, which is defined as the count of nodes along the longest path from the root to any leaf. The tree can contain anywhere from 0 to 10,000 nodes, with node values ranging from -100 to 100.

## Approach

This solution uses a recursive depth-first search approach. The base case checks if the current node is null, returning 0 to indicate no depth contribution. For any non-null node, the function recursively computes the maximum depth of both the left and right subtrees. It then returns 1 (counting the current node) plus the maximum of the two subtree depths. This elegantly captures the idea that a node's depth is one more than the deeper of its two children, and the recursion naturally explores all paths to leaves.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-13 01:21 UTC
- Runtime: 8 ms
- Memory: 17.8 MB
- Language: C++
