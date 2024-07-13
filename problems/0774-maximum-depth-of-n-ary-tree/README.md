# Maximum Depth of N-ary Tree

**Difficulty:** Easy
**Tags:** tree, depth-first-search, recursion, n-ary-tree

## Problem

Given an n-ary tree where each node can have any number of children, determine the maximum depth of the tree. The depth is defined as the count of nodes along the longest path from the root to any leaf node. The tree can contain up to 10,000 nodes with a maximum depth of 1,000.

## Approach

The solution uses a recursive depth-first search approach. For each node, it recursively computes the maximum depth among all of its children by iterating through the `children` vector. The base case handles an empty tree by returning 0. For each child node, the function calls itself recursively and tracks the maximum depth seen so far using a simple loop and `max` comparison. Finally, it returns 1 (for the current node) plus the maximum depth found among all children, which naturally propagates the deepest path length back up to the root.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-13 02:13 UTC
- Runtime: 12 ms
- Memory: 14.4 MB
- Language: C++
