# Sum Root to Leaf Numbers

**Difficulty:** Medium
**Tags:** tree, depth-first-search, binary-tree, recursion

## Problem

Given a binary tree where each node contains a single digit (0-9), compute the sum of all numbers formed by root-to-leaf paths, where each path represents a number by concatenating digits from root to leaf. The tree has at most 1000 nodes, a maximum depth of 10, and all results fit in a 32-bit integer.

## Approach

The solution uses depth-first search (DFS) to traverse all paths from root to leaf. It maintains a running number `cur` that represents the current path's numeric value by multiplying by 10 and adding each node's digit as it descends. When a leaf node (no children) is reached, the complete path number is added to a running `total` that accumulates the sum across all paths. The `total` is passed by reference so all recursive calls share and update the same accumulator. The recursion naturally backtracks after exploring each branch, allowing `cur` to be passed by value so each subtree gets the correct prefix without explicit restoration.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-04 03:53 UTC
- Runtime: 0 ms
- Memory: 11.3 MB
- Language: C++
