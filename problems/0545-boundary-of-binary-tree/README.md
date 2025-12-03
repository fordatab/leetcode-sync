# Boundary of Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, tree-traversal, depth-first-search, recursion

## Problem

Given a binary tree, construct its boundary traversal by concatenating: the root value, nodes along the left boundary (excluding leaves), all leaf nodes from left to right, and nodes along the right boundary in reverse order (excluding leaves). The left boundary follows the leftmost path prioritizing left children over right children, and the right boundary follows the rightmost path prioritizing right children over left children. Trees can have between 1 and 10,000 nodes with values ranging from -1000 to 1000.

## Approach

The solution divides the boundary into four separate components collected via recursive traversal:

1. **Left boundary**: Starting from the root's left child, traverse down by preferring the left child; if absent, take the right child. Only non-leaf nodes are added to the result.

2. **Right boundary**: Starting from the root's right child, traverse down by preferring the right child; if absent, take the left child. Only non-leaf nodes are collected, then reversed before final concatenation.

3. **Leaves**: A standard recursive traversal collects all leaf nodes (nodes with no children) from both left and right subtrees in left-to-right order.

4. **Assembly**: The final result concatenates the root value, left boundary nodes, all leaves, and the reversed right boundary nodes into a single vector.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-03 11:58 UTC
- Runtime: 13 ms
- Memory: 21.6 MB
- Language: C++
