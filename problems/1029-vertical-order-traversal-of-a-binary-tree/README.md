# Vertical Order Traversal of a Binary Tree

**Difficulty:** Hard
**Tags:** binary-tree, depth-first-search, hash-table, sorting

## Problem

Given a binary tree, produce a vertical ordering where each node is assigned a column index based on its horizontal position (left children decrease column by 1, right children increase by 1). Nodes must be grouped by column from left to right, and within each column, sorted first by row (depth) and then by value when multiple nodes share the same position. The tree has 1 to 1000 nodes with values between 0 and 1000.

## Approach

The solution uses depth-first search to traverse the tree while tracking each node's column and row coordinates. Starting at (row=0, col=0) for the root, it recursively visits left children at (row+1, col-1) and right children at (row+1, col+1).

All nodes are collected into a `map<int, vector<pair<int, int>>>` where the key is the column index and the value is a vector of (row, value) pairs. Using a map ensures columns are automatically sorted from leftmost to rightmost.

After the DFS completes, the solution iterates through each column in the map. For each column's vector of (row, value) pairs, it sorts them (first by row, then by value due to pair's default comparison). Finally, it extracts just the values from the sorted pairs to build the result vector for that column.

The key insight is that storing nodes as (row, value) pairs allows a single sort operation to handle both the row-ordering requirement and the tie-breaking by value for nodes at the same position.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-18 07:53 UTC
- Runtime: 2 ms
- Memory: 16 MB
- Language: C++
