# Deepest Leaves Sum

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, tree-traversal, recursion

## Problem

Given a binary tree, compute the sum of all node values that appear at the maximum depth level. The tree can contain between 1 and 10,000 nodes, with each node value ranging from 1 to 100.

## Approach

The solution uses a two-pass approach. First, it calculates the maximum depth of the tree using a recursive `depth` function that returns 1 plus the maximum depth of the left and right subtrees. Once the deepest level is known, a second recursive function `dfs` traverses the tree while tracking the remaining distance to the target depth. When a leaf node is encountered at depth 1 (meaning it's at the deepest level), its value is returned; otherwise, the function sums the results from both subtrees. Non-leaf nodes or nodes not at the target depth contribute their children's sums, effectively accumulating only the values from the deepest leaves.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-26 00:05 UTC
- Runtime: 69 ms
- Memory: 58.4 MB
- Language: C++
