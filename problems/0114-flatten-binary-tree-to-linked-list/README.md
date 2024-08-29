# Flatten Binary Tree to Linked List

**Difficulty:** Medium
**Tags:** binary-tree, tree-traversal, in-place-modification, morris-traversal, linked-list

## Problem

Transform a binary tree in-place so that each node's left pointer becomes null and its right pointer forms a linked-list structure. The resulting structure must follow the same ordering as a pre-order traversal (root, left subtree, right subtree) of the original tree. The tree can have up to 2000 nodes with values between -100 and 100.

## Approach

The solution uses an iterative Morris-style traversal approach that modifies the tree in-place without using extra space for recursion or a stack. Starting from the root, it processes each node by first checking if it has a left child. When a left child exists, the algorithm finds the rightmost node in the left subtree (by following right pointers until reaching null). This rightmost node's right pointer is then set to point to the current node's original right child, effectively threading the right subtree onto the end of the left subtree. The left subtree is then moved to become the new right child, and the left pointer is set to null. The current pointer advances to the right, and this process repeats until all nodes are processed. This effectively "flattens" the tree by rewiring pointers so that the pre-order traversal order is preserved in a right-leaning chain.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-29 23:38 UTC
- Runtime: 10 ms
- Memory: 17 MB
- Language: C++
