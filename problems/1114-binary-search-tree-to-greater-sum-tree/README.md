# Binary Search Tree to Greater Sum Tree

**Difficulty:** Medium
**Tags:** binary-search-tree, tree-traversal, in-order-traversal, recursion

## Problem

Transform a binary search tree so that each node's value becomes the sum of its original value plus all values greater than it in the tree. The tree has between 1 and 100 nodes with unique values ranging from 0 to 100. The BST property must be maintained structurally, though node values will change.

## Approach

The solution uses a two-pass approach. First, it calculates the total sum of all node values in the tree using a recursive helper function `s()` that traverses the entire tree. Then, it performs an in-order traversal (left-root-right) via the `dfs()` function, maintaining a running sum that starts at the total. At each node during the traversal, the code replaces the node's value with the current running sum, then decrements the running sum by the original node value. This works because in-order traversal of a BST visits nodes in ascending order, so when we process a node, the running sum represents the total of all values from that node upward (since we started with the full sum and have been subtracting smaller values encountered so far).

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-23 02:53 UTC
- Runtime: 0 ms
- Memory: 10.9 MB
- Language: C++
