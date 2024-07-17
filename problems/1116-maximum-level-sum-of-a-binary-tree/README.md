# Maximum Level Sum of a Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, breadth-first-search, queue, level-order-traversal

## Problem

Given a binary tree where the root is at level 1, find the smallest level number that has the maximum sum of node values. The tree can have between 1 and 10,000 nodes, and node values range from -100,000 to 100,000. If multiple levels have the same maximum sum, return the smallest level number.

## Approach

The solution uses a breadth-first search (BFS) with a queue to traverse the tree level by level. For each level, it calculates the sum of all node values by processing all nodes currently in the queue (tracked by capturing the queue size before processing). The algorithm maintains the current level number, the maximum sum seen so far (initialized to INT_MIN to handle negative sums), and the level that produced that maximum. After processing each level's nodes and adding their children to the queue, it compares the level's sum to the current maximum. If the new sum is strictly greater, it updates both the maximum sum and the result level. This ensures that when multiple levels have the same sum, the earliest level is retained. The process continues until all levels are processed, and the function returns the level number with the maximum sum.

## Complexity

- **Time:** O(n)
- **Space:** O(w)

## Stats

- Submitted: 2024-07-17 05:57 UTC
- Runtime: 148 ms
- Memory: 105.9 MB
- Language: C++
