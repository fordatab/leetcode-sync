# Path Sum II

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, backtracking, tree-traversal

## Problem

Find all root-to-leaf paths in a binary tree where the sum of node values equals a given target. A leaf is defined as a node with no children. The tree can have up to 5000 nodes, and both node values and the target sum range from -1000 to 1000.

## Approach

The solution uses depth-first search with backtracking to explore all paths from root to leaves. It maintains a running sum and a current path as it traverses the tree.

Starting from the root, the algorithm adds each node's value to both the running sum and the current path vector. When it reaches a leaf node (one with no children), it checks if the accumulated sum matches the target. If so, it saves a copy of the current path to the results.

After exploring both left and right subtrees recursively, the algorithm backtracks by popping the current node from the path vector. This allows the path vector to be reused correctly as the search explores different branches of the tree.

The base case handles null nodes by simply returning, which naturally occurs when exploring children of leaf nodes or when the tree itself is empty.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-31 02:18 UTC
- Runtime: 21 ms
- Memory: 19 MB
- Language: C++
