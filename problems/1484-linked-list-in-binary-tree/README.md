# Linked List in Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, linked-list, depth-first-search, recursion, tree-traversal

## Problem

Given a binary tree and a linked list, determine whether there exists a downward path in the tree whose node values match the entire linked list sequence from head to tail. A downward path starts at any tree node and proceeds only to child nodes. The tree can have up to 2500 nodes, the list up to 100 nodes, and all values are between 1 and 100.

## Approach

The solution uses a two-function recursive strategy. The main function `isSubPath` explores every node in the binary tree as a potential starting point for the linked list match. For each tree node, it calls `matchPath` to check if the linked list can be matched starting from that node.

The `matchPath` helper function attempts to match the linked list sequence with a downward path starting from a given tree node. It compares the current list node's value with the tree node's value, and if they match, recursively tries to match the rest of the list with either the left or right child of the tree node. This continues until either the entire list is matched (success) or a mismatch occurs.

If `matchPath` fails at the current tree node, `isSubPath` recursively explores both left and right subtrees to find other potential starting points. The recursion continues until either a complete match is found anywhere in the tree, or all nodes have been exhausted. Base cases handle null pointers: a null list head means the entire list has been matched successfully, while a null tree node during matching means the path ended prematurely.

## Complexity

- **Time:** O(n * m)
- **Space:** O(h + d)

## Stats

- Submitted: 2024-09-07 01:42 UTC
- Runtime: 30 ms
- Memory: 30.7 MB
- Language: C++
