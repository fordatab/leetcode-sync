# Longest ZigZag Path in a Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree, find the longest zigzag path where you alternate between going left and right at each step. A zigzag path can start from any node in any direction, and its length is the number of edges traversed (nodes visited minus one). The tree can have up to 50,000 nodes.

## Approach

The solution uses depth-first search (DFS) to explore all possible zigzag paths. The `dfs` function takes three parameters: the current node, a boolean indicating the direction we're expected to move (right or left), and the current depth of the zigzag path.

When moving in the correct zigzag direction (right when `is_right` is true, or left when `is_right` is false), the depth is incremented and the search continues in the opposite direction. When moving in the "wrong" direction (breaking the zigzag pattern), the depth resets to 0, effectively starting a new zigzag path from that point.

At each node, the function returns the maximum of two recursive calls: one that continues the zigzag pattern (incrementing depth) and one that starts fresh (resetting depth to 0). The main function initiates DFS from the root in both directions with an initial depth of -1, which becomes 0 when the first actual node is processed, and returns the maximum result.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-30 08:36 UTC
- Runtime: 132 ms
- Memory: 93.3 MB
- Language: C++
