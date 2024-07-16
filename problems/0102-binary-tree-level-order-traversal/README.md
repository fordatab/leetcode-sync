# Binary Tree Level Order Traversal

**Difficulty:** Medium
**Tags:** binary-tree, breadth-first-search, queue, level-order-traversal

## Problem

Given a binary tree's root node, produce a list of lists where each inner list contains all node values at a particular depth, ordered from left to right. The tree can have 0 to 2000 nodes with values between -1000 and 1000. An empty tree should return an empty result.

## Approach

The solution uses breadth-first search with a queue to traverse the tree level by level. It starts by handling the empty tree case, then initializes a queue with the root node.

For each level, the algorithm captures the current queue size (number of nodes at this level) and processes exactly that many nodes. During processing, it extracts each node from the front of the queue, collects its value into a temporary vector, and enqueues its left and right children if they exist.

After processing all nodes at the current level, the temporary vector containing that level's values is added to the result. This process repeats until the queue is empty, ensuring all levels are visited in order from top to bottom.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-16 23:54 UTC
- Runtime: 7 ms
- Memory: 15.2 MB
- Language: C++
