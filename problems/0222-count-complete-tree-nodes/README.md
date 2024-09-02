# Count Complete Tree Nodes

**Difficulty:** Easy
**Tags:** binary-tree, recursion, divide-and-conquer, tree-height, complete-binary-tree

## Problem

Given the root of a complete binary tree (where all levels are fully filled except possibly the last, which is filled left-to-right), count the total number of nodes. The tree can have 0 to 50,000 nodes, and the solution must run faster than O(n) time complexity by exploiting the complete tree property.

## Approach

The solution exploits the property of complete binary trees by checking if a subtree is perfect (all levels completely filled). It computes the height by traversing the leftmost path and the rightmost path from the current node. If these heights are equal, the subtree is a perfect binary tree with exactly 2^h - 1 nodes. If the heights differ, the tree is not perfect, so it recursively counts nodes in both left and right subtrees and adds 1 for the current node.

This approach avoids visiting every node when encountering perfect subtrees. At each recursive call, it either:
- Identifies a perfect subtree and returns its node count using the formula, or
- Recurses on both children when the subtree is not perfect.

The key insight is that in a complete binary tree, at least one of the two subtrees at any node must be perfect, allowing the algorithm to skip fully counting those nodes and instead use the mathematical formula.

## Complexity

- **Time:** O(log^2 n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-09-02 06:34 UTC
- Runtime: 24 ms
- Memory: 29.5 MB
- Language: C++
