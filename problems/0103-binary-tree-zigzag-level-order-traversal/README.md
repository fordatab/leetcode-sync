# Binary Tree Zigzag Level Order Traversal

**Difficulty:** Medium
**Tags:** binary-tree, breadth-first-search, level-order-traversal, queue

## Problem

Given a binary tree's root node, traverse it level by level and collect node values in a zigzag pattern: the first level is read left-to-right, the second level right-to-left, and so on, alternating direction for each successive level. The tree can contain up to 2000 nodes with values between -100 and 100, and an empty tree should return an empty result.

## Approach

The solution uses breadth-first search (BFS) with a queue to perform level-order traversal. For each level, it processes all nodes currently in the queue (tracked by storing the queue size at the start of each iteration), collecting their values in a temporary vector while enqueuing their children for the next level.

A `forward` counter tracks the current level number (starting at 0, incremented at the beginning of each level). After collecting all values for a level, the solution checks if the level number is even using modulo 2 arithmetic. If the level is even (which corresponds to the second, fourth, sixth levels due to the increment timing), the collected values are reversed using `std::reverse` to achieve the zigzag effect.

The alternating pattern works because odd values of `forward` (1, 3, 5...) represent levels that should be left-to-right, while even values (2, 4, 6...) represent levels that should be right-to-left. Each completed level's vector is appended to the output, building the final zigzag traversal result.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-17 00:21 UTC
- Runtime: 0 ms
- Memory: 13.3 MB
- Language: C++
