# Balanced Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree with up to 5000 nodes (node values ranging from -10^4 to 10^4), determine whether it is height-balanced. A height-balanced tree is one where for every node, the heights of its left and right subtrees differ by at most one. An empty tree is considered balanced.

## Approach

The solution uses a recursive depth-first search that simultaneously checks balance and computes height. The `dfs` function returns a pair: a boolean indicating whether the subtree is balanced, and an integer representing its height.

For each node, it recursively processes both children. If a child returns false (unbalanced), that failure propagates upward. If both children are balanced, it checks whether their height difference is at most 1. When the subtree rooted at the current node is balanced, it returns true along with the height (1 plus the maximum of the two child heights). Otherwise, it returns false with a sentinel value (-1).

The main function invokes `dfs` on the root and extracts the boolean result, discarding the height information. This approach avoids redundant height recalculations by computing balance and height in a single traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-16 09:57 UTC
- Runtime: 11 ms
- Memory: 21.9 MB
- Language: C++
