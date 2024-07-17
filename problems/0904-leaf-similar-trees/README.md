# Leaf-Similar Trees

**Difficulty:** Easy
**Tags:** tree, depth-first-search, binary-tree, recursion

## Problem

Given two binary trees, determine if they have identical leaf value sequences. A leaf value sequence is formed by reading all leaf nodes from left to right. The trees can have up to 200 nodes each, with node values ranging from 0 to 200.

## Approach

The solution uses a depth-first traversal to extract leaf sequences from both trees, then compares them for equality.

A helper function `leaves` recursively traverses each tree. When it encounters a node with no children (a leaf), it appends that node's value to a reference vector. Non-leaf nodes simply trigger recursive calls on their left and right children.

The main function calls `leaves` twice—once for each input tree—populating two separate vectors `a` and `b`. It then returns whether these vectors are equal, which in C++ compares both length and element-by-element values.

This approach is straightforward: collect all leaves in order, then check if the two collections match.

## Complexity

- **Time:** O(n + m)
- **Space:** O(h1 + h2)

## Stats

- Submitted: 2024-07-17 07:36 UTC
- Runtime: 0 ms
- Memory: 14.5 MB
- Language: C++
