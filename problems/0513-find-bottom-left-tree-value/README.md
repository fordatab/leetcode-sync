# Find Bottom Left Tree Value

**Difficulty:** Medium
**Tags:** binary-tree, breadth-first-search, queue, level-order-traversal

## Problem

Given a binary tree with 1 to 10,000 nodes where each node's value is a 32-bit signed integer, find and return the value of the leftmost node in the deepest (bottom-most) level of the tree. The tree is guaranteed to have at least one node.

## Approach

The solution uses a two-phase approach. First, it recursively computes the maximum depth of the tree using a helper function that returns 1 plus the maximum depth of the left and right subtrees. Second, it performs a level-order traversal (BFS) using a queue, processing nodes level by level. For each level, it tracks the current level number and processes all nodes at that level from left to right. When the current level matches the pre-computed maximum depth, it immediately returns the value of the first node encountered at that level, which is guaranteed to be the leftmost node due to the left-to-right processing order of BFS.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-03 01:38 UTC
- Runtime: 27 ms
- Memory: 23.8 MB
- Language: C++
