# Binary Search Tree Iterator

**Difficulty:** Medium
**Tags:** binary-search-tree, stack, iterator, tree-traversal, in-order-traversal

## Problem

Design an iterator that traverses a binary search tree in sorted (in-order) sequence. The iterator must support initialization with a BST root, a next() method that returns the next smallest element, and a hasNext() method that checks if more elements remain. The tree can have up to 100,000 nodes, and up to 100,000 method calls will be made.

## Approach

The solution uses a stack to simulate an iterative in-order traversal without pre-computing all values. During initialization, the constructor pushes the root onto the stack and then follows all left children, pushing each onto the stack until reaching the leftmost (smallest) node.

When next() is called, it pops the top node from the stack (which is always the next smallest unvisited node), retrieves its value, and then handles the right subtree. If the popped node has a right child, that right child is pushed onto the stack, followed by all of its left descendants via the push_l helper function.

The hasNext() method simply checks whether the stack is empty. The stack maintains the invariant that its top always contains the next node to visit in in-order sequence, and nodes are processed left-root-right as in standard in-order traversal.

## Complexity

- **Time:** O(1)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-02 06:44 UTC
- Runtime: 20 ms
- Memory: 29.2 MB
- Language: C++
