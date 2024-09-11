# Reverse Odd Levels of Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a perfect binary tree, reverse the node values at each odd-numbered level (where the root is level 0). A perfect binary tree has all parent nodes with exactly two children and all leaves at the same depth. The tree can contain up to 2^14 nodes, with values ranging from 0 to 10^5. Return the root of the modified tree.

## Approach

The solution uses a recursive approach that simultaneously traverses pairs of nodes from opposite sides of each level. Starting from the root's children, it recursively processes corresponding left and right subtrees at each level.

At each recursive call, the function tracks the current level number. When the level is odd, it swaps the values of the paired nodes (left node with its mirror-right node). The key insight is that in a perfect binary tree, we can process nodes in symmetric pairs: for level traversal, the left child of the left subtree pairs with the right child of the right subtree, and vice versa.

The recursion continues with two calls: one pairing the outer children (left's left with right's right) and another pairing the inner children (left's right with right's left). This ensures that all nodes at each odd level are properly reversed through successive swaps. The base case occurs when null nodes are reached, indicating we've traversed beyond the leaves.

## Complexity

- **Time:** O(n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-09-11 23:13 UTC
- Runtime: 159 ms
- Memory: 71.9 MB
- Language: C++
