# Convert Sorted List to Binary Search Tree

**Difficulty:** Medium
**Tags:** linked-list, binary-search-tree, divide-and-conquer, recursion, two-pointers

## Problem

Given a singly linked list with elements in ascending order, construct a height-balanced binary search tree. The list can contain up to 20,000 nodes with values ranging from -100,000 to 100,000. A height-balanced BST is one where the depth of the two subtrees of every node never differs by more than one.

## Approach

The solution uses an in-order traversal simulation to build the BST bottom-up. First, it calculates the total length of the linked list to determine index boundaries. It maintains a pointer `current` that tracks the current position in the linked list as it traverses.

The recursive `convertListToBST` function takes index bounds (left and right) representing a range in the sorted sequence. For each range, it calculates the middle index and recursively builds the left subtree first (covering indices from left to mid-1). After the left subtree is complete, the current list node becomes the root of this subtree, and `current` advances to the next node. Finally, it recursively builds the right subtree (from mid+1 to right).

This in-order approach ensures that nodes from the linked list are consumed in sequence from left to right while building the tree structure, and the middle-element selection at each level guarantees height balance. The recursion naturally follows the in-order traversal pattern: process left, then root, then right.

## Complexity

- **Time:** O(n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-02 03:56 UTC
- Runtime: 17 ms
- Memory: 29.1 MB
- Language: C++
