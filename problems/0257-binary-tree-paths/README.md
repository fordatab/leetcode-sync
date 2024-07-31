# Binary Tree Paths

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, backtracking, recursion, tree-traversal

## Problem

Given a binary tree's root node, find all paths from the root to each leaf node and return them as strings. Each path should be formatted with node values separated by "->" arrows. The tree contains between 1 and 100 nodes with values ranging from -100 to 100.

## Approach

This solution uses depth-first search (DFS) with backtracking to explore all root-to-leaf paths. It maintains a `path` vector that accumulates node values as strings during traversal. When the DFS reaches a leaf node (a node with no children), it joins the accumulated path elements with "->" delimiters using a helper `join` function and adds the resulting string to the output vector. After exploring both subtrees of each node, the current node's value is popped from the path vector to backtrack, allowing the path to be reused for exploring other branches. The recursive DFS function processes the left subtree before the right subtree, building up complete paths incrementally.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-31 02:02 UTC
- Runtime: 4 ms
- Memory: 16.3 MB
- Language: C++
