# Serialize and Deserialize Binary Tree

**Difficulty:** Hard
**Tags:** binary-tree, depth-first-search, tree-traversal, serialization, string-manipulation

## Problem

Given a binary tree, implement methods to convert it into a string representation and reconstruct the tree from that string. The tree can have up to 10,000 nodes with integer values between -1000 and 1000. Any serialization format is acceptable as long as the deserialized tree matches the original structure.

## Approach

The solution uses **preorder depth-first traversal** for both serialization and deserialization.

**Serialization:** Recursively traverse the tree in preorder (root, left, right). For each node, append its value followed by a comma delimiter to the output string. Null nodes are represented as "N" followed by a comma. This creates a comma-separated sequence that captures the tree structure.

**Deserialization:** First, split the serialized string by commas into a vector of tokens. Then recursively rebuild the tree using preorder traversal with an index pointer tracking the current position in the token vector. When encountering "N", return nullptr and increment the index. Otherwise, create a node with the current value, increment the index, and recursively build its left and right subtrees.

The key insight is that preorder traversal with explicit null markers uniquely determines a binary tree structure, allowing faithful reconstruction without ambiguity.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-20 00:52 UTC
- Runtime: 36 ms
- Memory: 37.2 MB
- Language: C++
