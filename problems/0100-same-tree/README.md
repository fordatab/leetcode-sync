# Same Tree

**Difficulty:** Easy
**Tags:** binary-tree, recursion, depth-first-search, tree-traversal

## Problem

Determine whether two binary trees are identical in both structure and node values. Trees can have between 0 and 100 nodes, with node values ranging from -10,000 to 10,000. Two trees are considered the same only if every corresponding position has either both null nodes or both non-null nodes with matching values.

## Approach

The solution uses a recursive depth-first traversal to compare the trees node by node. At each recursive call, it first checks if both nodes are null (base case for identical subtrees). If exactly one node is null or the values differ, the trees cannot be the same. Otherwise, it recursively checks both the left and right subtrees, returning true only if both subtree comparisons succeed. This approach directly mirrors the tree structure by making parallel recursive calls on corresponding children.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-14 08:52 UTC
- Runtime: 0 ms
- Memory: 12.2 MB
- Language: C++
