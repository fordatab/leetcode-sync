# Evaluate Boolean Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, recursion, depth-first-search, tree-traversal

## Problem

Given a full binary tree where leaf nodes contain boolean values (0 for false, 1 for true) and internal nodes contain operators (2 for OR, 3 for AND), compute the boolean result by recursively evaluating the tree from leaves upward, applying the appropriate operator at each internal node. The tree has between 1 and 1000 nodes, and every node has exactly 0 or 2 children.

## Approach

The solution uses a recursive depth-first traversal of the binary tree. For each node, it first recursively evaluates both the left and right subtrees to obtain boolean results. Then it checks the current node's value: if the value is 2, it applies the OR operation to the two child results; if the value is 3, it applies the AND operation; if the value is 1, it returns true (leaf with value 1); otherwise it returns false (leaf with value 0). The recursion naturally handles the bottom-up evaluation, computing leaf values first and propagating results upward through the operators until the root is evaluated.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-31 00:53 UTC
- Runtime: 12 ms
- Memory: 17.5 MB
- Language: C++
