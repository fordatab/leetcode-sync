# Sum of Root To Leaf Binary Numbers

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, backtracking, recursion

## Problem

Given a binary tree where each node contains either 0 or 1, compute the sum of all binary numbers formed by root-to-leaf paths. Each path represents a binary number with the root as the most significant bit. The tree can have up to 1000 nodes, and the result fits in a 32-bit integer.

## Approach

The solution uses depth-first search (DFS) with backtracking to traverse all root-to-leaf paths. It maintains a `path` vector that stores the binary digits encountered from root to the current node. When a leaf node is reached, the code converts the collected binary digits into a decimal number by iterating through the path, doubling the running total at each step and adding 1 if the current digit is 1. This decimal value is accumulated into a `total` variable passed by reference. After processing a node's subtrees, the current node's value is removed from the path (backtracking) to correctly handle sibling paths. The solution explores both left and right subtrees recursively, ensuring all root-to-leaf paths contribute to the final sum.

## Complexity

- **Time:** O(n * h)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-31 01:35 UTC
- Runtime: 20 ms
- Memory: 16.2 MB
- Language: C++
