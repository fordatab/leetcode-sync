# Minimum Depth of Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree, determine the length of the shortest path from the root to any leaf node, where a leaf is defined as a node with no children. The tree can contain between 0 and 100,000 nodes with values ranging from -1000 to 1000.

## Approach

The solution uses depth-first search (DFS) to traverse the entire tree while tracking the current depth. It maintains a global minimum depth variable initialized to INT_MAX.

Starting from the root with depth 1, the algorithm recursively explores both left and right subtrees, incrementing the depth at each level. When a leaf node is encountered (a node with no left or right children), the current depth is compared against the running minimum and updated if smaller.

A special case handles an empty tree: if the root is null and we're at depth 1, the minimum is set to 0. The recursion explores all paths to all leaves, ensuring the true minimum depth is found even in unbalanced trees where the shortest path might not be along the leftmost or rightmost edge.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-31 02:58 UTC
- Runtime: 189 ms
- Memory: 145 MB
- Language: C++
