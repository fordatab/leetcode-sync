# Root Equals Sum of Children

**Difficulty:** Easy
**Tags:** binary-tree, tree

## Problem

Given a binary tree with exactly three nodes (a root and its two children), determine whether the root's value equals the sum of its left and right child values. Node values can range from -100 to 100.

## Approach

The solution directly compares the root's value against the sum of its two children's values in a single expression. It accesses the `val` field of the root node and adds the `val` fields of both the left and right child nodes, then returns whether this equality holds. Since the tree is guaranteed to have exactly three nodes, no null checks or tree traversal is needed.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-31 00:01 UTC
- Runtime: 0 ms
- Memory: 14.6 MB
- Language: C++
