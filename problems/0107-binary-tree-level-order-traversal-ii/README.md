# Binary Tree Level Order Traversal II

**Difficulty:** Medium
**Tags:** binary-tree, breadth-first-search, level-order-traversal, queue

## Problem

Given a binary tree root, return the values of nodes organized by level, but with the levels listed in reverse order (deepest level first, root level last). Each level's nodes should be listed from left to right. The tree can have between 0 and 2000 nodes, with values ranging from -1000 to 1000.

## Approach

The solution performs a standard breadth-first search (BFS) traversal using a queue to process nodes level by level. Starting from the root, it maintains a queue of nodes to visit. For each level, it records the current queue size to know how many nodes belong to that level, then processes exactly that many nodes: extracting each node's value into a temporary vector while enqueueing its children (left then right) for the next level. Each completed level is added to the output vector. After all levels are collected in top-down order, the entire result vector is reversed to achieve the required bottom-up ordering before returning.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-17 00:08 UTC
- Runtime: 0 ms
- Memory: 14.1 MB
- Language: C++
