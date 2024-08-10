# Sum of Left Leaves

**Difficulty:** Easy
**Tags:** binary-tree, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree, compute the sum of values from all leaf nodes that are left children of their parent. A leaf is defined as a node with no children. The tree can contain 1 to 1000 nodes with values ranging from -1000 to 1000.

## Approach

The solution uses a depth-first search (DFS) traversal with an additional boolean parameter to track whether the current node is a left child of its parent. The main function initializes a sum variable and calls the recursive helper.

The `dfs` helper function takes three parameters: the current node, a flag indicating if it's a left child, and a reference to the accumulating sum. At each node, it checks if the node is both a left child (via the flag) and a leaf (no left or right children). If both conditions are true, the node's value is added to the sum.

The recursion continues by visiting the left subtree with `is_left=true` and the right subtree with `is_left=false`. The sum is accumulated through the reference parameter, eliminating the need to return values and combine them up the call stack.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-10 00:13 UTC
- Runtime: 0 ms
- Memory: 14.8 MB
- Language: C++
