# Range Sum of BST

**Difficulty:** Easy
**Tags:** binary-search-tree, tree, recursion, depth-first-search

## Problem

Given a binary search tree and two boundary integers, compute the sum of all node values that fall within the closed interval defined by those boundaries. The tree can contain up to 20,000 nodes, with node values and boundaries ranging from 1 to 100,000, and all node values are distinct.

## Approach

The solution uses a recursive depth-first traversal of the entire BST. At each node, it checks whether the current node's value falls within the specified range [low, high]. If it does, the value is added to a running sum. The function then recursively explores both the left and right subtrees, accumulating their sums. The base case returns 0 when encountering a null node. The key insight is straightforward recursion: check the current node, then sum the results from both children, without leveraging the BST property to prune unnecessary branches.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-22 11:24 UTC
- Runtime: 92 ms
- Memory: 63.3 MB
- Language: C++
