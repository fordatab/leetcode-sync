# Validate Binary Search Tree

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, recursion, binary-search-tree, tree-traversal

## Problem

Given a binary tree, determine whether it satisfies the binary search tree properties: each node's value must be strictly greater than all values in its left subtree and strictly less than all values in its right subtree, with both subtrees also being valid BSTs. The tree can contain between 1 and 10,000 nodes, with values ranging from -2^31 to 2^31 - 1.

## Approach

The solution uses a recursive depth-first search with range constraints. Each recursive call passes down a valid range `(l, r)` that the current node's value must fall within. Initially, the root can be any value, so the range is `(LONG_MIN, LONG_MAX)`.

When visiting a node, the code first checks if it's null (base case returning true). Then it verifies that the node's value is strictly between the lower and upper bounds. If this check fails, the subtree is invalid.

For valid nodes, the recursion continues: the left child is checked with an updated upper bound of the current node's value, and the right child is checked with an updated lower bound of the current node's value. This ensures that all descendants respect the BST property relative to their ancestors.

The use of `long` instead of `int` for the bounds handles edge cases where node values might be at the extreme ends of the 32-bit integer range.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-17 02:20 UTC
- Runtime: 8 ms
- Memory: 20.2 MB
- Language: C++
