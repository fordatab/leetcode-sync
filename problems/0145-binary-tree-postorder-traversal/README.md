# Binary Tree Postorder Traversal

**Difficulty:** Easy
**Tags:** binary-tree, tree-traversal, stack, postorder

## Problem

Given a binary tree's root node, produce a list of node values visited in postorder sequence (left subtree, right subtree, then root). The tree can have 0 to 100 nodes with values ranging from -100 to 100. The challenge encourages an iterative solution rather than the straightforward recursive approach.

## Approach

This solution uses an iterative approach with a stack and a clever reversal trick. Instead of performing true postorder traversal (left-right-root), it simulates a modified preorder traversal (root-right-left) and builds the result in reverse order.

The algorithm pushes the root onto a stack, then repeatedly pops nodes and inserts their values at the beginning of the result vector. For each popped node, it pushes the left child first, then the right child onto the stack. This ensures that right children are processed before left children.

By inserting values at the front of the vector (`v.insert(v.begin(), p->val)`), the root-right-left traversal order gets reversed into the desired left-right-root postorder. The stack handles the iteration without recursion, though the frequent insertions at the beginning of the vector make this approach less efficient than optimal iterative solutions.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-31 03:15 UTC
- Runtime: 4 ms
- Memory: 10.1 MB
- Language: C++
