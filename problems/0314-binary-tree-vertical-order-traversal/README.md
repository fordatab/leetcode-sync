# Binary Tree Vertical Order Traversal

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, hash-table, sorting

## Problem

Given a binary tree, group all nodes by their horizontal column position (where moving left decreases the column index and moving right increases it), then return these groups ordered by column from left to right. Within each column, nodes must appear in top-to-bottom order, and if multiple nodes share the same row and column, they should be ordered left-to-right. The tree can have 0 to 100 nodes with values ranging from -100 to 100.

## Approach

The solution uses a depth-first search (DFS) traversal to assign each node a column index and row index. The root starts at column 0 and row 0; going left decrements the column and going right increments it, while going down always increments the row.

A `map<int, vector<pair<int, int>>>` stores nodes grouped by column index, where each entry maps a column to a vector of (row, value) pairs. The map automatically keeps columns sorted by key.

After the DFS populates the map, the code iterates through each column in order. For each column's vector of (row, value) pairs, it sorts by row index to ensure top-to-bottom ordering. Nodes at the same row naturally maintain left-to-right order because DFS visits left children before right children.

Finally, it extracts just the node values from each sorted column and builds the result as a 2D vector where each inner vector represents one vertical column.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-18 08:06 UTC
- Runtime: 3 ms
- Memory: 16 MB
- Language: C++
