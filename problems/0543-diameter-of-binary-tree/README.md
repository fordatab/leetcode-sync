# Diameter of Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree, find the longest path between any two nodes measured in edges. This path can traverse any route through the tree and doesn't need to include the root. The tree contains between 1 and 10,000 nodes with integer values ranging from -100 to 100.

## Approach

The solution uses a depth-first search (DFS) traversal with a pass-by-reference variable to track the maximum diameter. The `dfs` function recursively computes the height of each subtree while simultaneously checking if the path through the current node (left height + right height) forms a new maximum diameter.

At each node, the function calculates the height of the left and right subtrees, then updates the diameter if the sum of these heights exceeds the current maximum. The function returns `1 + max(left_height, right_height)` to provide the height of the current subtree to its parent.

This approach works because the longest path either passes through a node (using both its left and right subtrees) or lies entirely within one of its subtrees. By checking every node and maintaining a running maximum, we're guaranteed to find the diameter. The key insight is that we can compute both the height information (needed for parent nodes) and the diameter (the actual answer) in a single traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-16 09:42 UTC
- Runtime: 14 ms
- Memory: 22.5 MB
- Language: C++
