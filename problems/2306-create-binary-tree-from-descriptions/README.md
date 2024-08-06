# Create Binary Tree From Descriptions

**Difficulty:** Medium
**Tags:** hash-table, binary-tree, tree-construction

## Problem

Given an array of parent-child-direction triplets, construct and return the root of a binary tree where each triplet specifies a parent node, its child node, and whether that child is a left or right child. All node values are unique, and the input is guaranteed to form a valid binary tree with up to 10^4 descriptions and node values up to 10^5.

## Approach

The solution uses two hash maps to build the tree in two passes. In the first pass, it creates a `TreeNode` for every unique value that appears as either a parent or child, storing these nodes in a hash map keyed by their values. It also creates a copy of this map to track potential root candidates.

In the second pass, it iterates through the descriptions again to establish parent-child relationships by setting the `left` or `right` pointers based on the `isLeft` flag. Simultaneously, it removes each child node from the copied map, since any node that is someone's child cannot be the root.

After processing all descriptions, the copied map contains only nodes that were never listed as children—exactly one such node exists (the root). The solution returns this remaining node by accessing the first element of the copied map.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-06 00:55 UTC
- Runtime: 797 ms
- Memory: 304.6 MB
- Language: C++
