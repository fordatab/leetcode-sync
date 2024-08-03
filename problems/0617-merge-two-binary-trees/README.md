# Merge Two Binary Trees

**Difficulty:** Easy
**Tags:** binary-tree, recursion, depth-first-search, tree-traversal

## Problem

Given two binary trees, merge them into a single tree where overlapping nodes have their values summed, and non-overlapping nodes are preserved as-is. Each tree can have 0 to 2000 nodes with values ranging from -10⁴ to 10⁴. The merge must begin at the root and proceed recursively through corresponding positions in both trees.

## Approach

This solution uses a recursive depth-first approach that modifies the first tree in place. When both nodes exist at corresponding positions, it adds the second node's value to the first node's value, then recursively merges their left and right subtrees. When only one node exists at a position (either from tree1 or tree2), that node becomes the result at that position. The base case returns whichever node is non-null, or null if both are null. By reusing the first tree's structure and only creating new nodes when necessary from the second tree, the solution minimizes memory allocation.

## Complexity

- **Time:** O(min(m, n))
- **Space:** O(min(m, n))

## Stats

- Submitted: 2024-08-03 02:07 UTC
- Runtime: 28 ms
- Memory: 33.3 MB
- Language: C++
