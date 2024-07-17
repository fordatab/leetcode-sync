# Binary Tree Right Side View

**Difficulty:** Medium
**Tags:** binary-tree, breadth-first-search, level-order-traversal, queue

## Problem

Given a binary tree's root, return the values visible when viewing the tree from the right side, ordered top to bottom. Each level contributes exactly one node: the rightmost node at that depth. The tree can have 0 to 100 nodes with values between -100 and 100.

## Approach

The solution uses level-order traversal (BFS) with a queue to process the tree one level at a time. For each level, it iterates through all nodes currently in the queue (determined by capturing the queue size at the start of each level). As it processes nodes, it enqueues their children (left then right) for the next level. The key insight is tracking which node is the last one in each level: when the loop index reaches `size-1`, that node's value is stored in a temporary variable `o`, which is then appended to the output vector after completing the level. This ensures only the rightmost node from each level is collected.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-17 01:05 UTC
- Runtime: 7 ms
- Memory: 14.5 MB
- Language: C++
