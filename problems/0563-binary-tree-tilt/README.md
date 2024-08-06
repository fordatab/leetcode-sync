# Binary Tree Tilt

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, post-order-traversal

## Problem

Given a binary tree, compute the sum of tilts across all nodes, where each node's tilt is defined as the absolute difference between the sum of values in its left subtree and the sum of values in its right subtree. Trees can have up to 10,000 nodes with values ranging from -1000 to 1000, and missing children are treated as having a subtree sum of zero.

## Approach

The solution uses a depth-first search (DFS) that performs a post-order traversal of the tree. For each node, the `dfs` function recursively computes the sum of all values in the left and right subtrees. At each node, it calculates the tilt as the absolute difference between these two sums and accumulates it into a running total passed by reference. The function then returns the total sum of the current subtree (node value plus left and right subtree sums) to its parent. This ensures each node's tilt is computed once during the traversal while simultaneously building up the subtree sums needed by ancestor nodes.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-06 00:04 UTC
- Runtime: 8 ms
- Memory: 22.4 MB
- Language: C++
