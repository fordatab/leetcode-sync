# Path Sum

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree and a target integer, determine whether any path from the root to a leaf node sums to the target value. A leaf is defined as a node without children. The tree can have up to 5000 nodes, with node values and the target both ranging from -1000 to 1000.

## Approach

The solution uses a recursive depth-first search approach. At each node, it first checks if the current node is null (base case for recursion returning false). Then it checks if the current node is a leaf (no left or right children) and whether the remaining target equals the current node's value—if so, a valid path is found. Otherwise, it recursively explores both left and right subtrees, subtracting the current node's value from the target sum for each recursive call. The function returns true if either subtree finds a valid path.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-31 02:23 UTC
- Runtime: 13 ms
- Memory: 19.8 MB
- Language: C++
