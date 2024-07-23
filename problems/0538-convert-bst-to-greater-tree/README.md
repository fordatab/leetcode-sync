# Convert BST to Greater Tree

**Difficulty:** Medium
**Tags:** binary-search-tree, tree-traversal, in-order-traversal, recursion, depth-first-search

## Problem

Given a binary search tree, transform it so that each node's value becomes the sum of its original value plus all values greater than it in the tree. The tree has up to 10,000 nodes with unique values ranging from -10,000 to 10,000. The transformation should modify the tree in-place while maintaining its structure.

## Approach

The solution uses a two-pass approach. First, it computes the total sum of all node values in the tree with a recursive helper function `s()`. Then, it performs an in-order traversal (left-root-right) using `dfs()`, maintaining a running accumulator initialized to the total sum.

During the in-order traversal, at each node, it:
1. Recursively processes the left subtree
2. Saves the current node's original value, replaces it with the accumulator (which represents the sum of all remaining unprocessed values)
3. Subtracts the original value from the accumulator
4. Recursively processes the right subtree

This works because in-order traversal visits nodes in ascending order in a BST. By tracking the remaining sum and subtracting each visited value, each node gets assigned the sum of itself plus all greater values that will be visited later in the traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-23 02:54 UTC
- Runtime: 24 ms
- Memory: 34.4 MB
- Language: C++
