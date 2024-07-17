# Count Good Nodes in Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, tree-traversal, recursion

## Problem

Given a binary tree, count how many nodes are "good" where a node is considered good if no ancestor node in the path from root to that node has a value strictly greater than it. The tree can have up to 100,000 nodes with values ranging from -10,000 to 10,000.

## Approach

The solution uses a depth-first search (DFS) traversal that tracks the maximum value encountered along the path from the root to the current node. At each node, it checks if the current node's value is greater than or equal to the maximum seen so far on the path. If so, the node is counted as "good" and the maximum is updated to the current node's value. The algorithm recursively processes both left and right subtrees, passing down the updated maximum value, and accumulates the count of good nodes from all branches. The base case returns 0 for null nodes, and the counts from left and right subtrees are summed together with the current node's contribution.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-17 01:52 UTC
- Runtime: 97 ms
- Memory: 84.8 MB
- Language: C++
