# Delete Node in a BST

**Difficulty:** Medium
**Tags:** binary-search-tree, tree, binary-tree, iterative

## Problem

Given a binary search tree and a target key, remove the node containing that key while maintaining the BST property, then return the root of the modified tree. The tree can have up to 10,000 nodes with unique values ranging from -100,000 to 100,000, and the key to delete is also in this range.

## Approach

The solution uses an iterative approach with three distinct deletion cases:

**Finding the target:** A while loop traverses the BST, tracking both the current node and its parent. It navigates left or right based on BST ordering until finding the target key or reaching null.

**Case 1 - Leaf node:** If the target has no children, the code updates the parent's pointer to null (or returns null if deleting the root) and deallocates the node.

**Case 2 - One child:** If the target has exactly one child, that child replaces the target in the tree by updating the parent's pointer (or returning the child if deleting the root), then deallocates the target.

**Case 3 - Two children:** When the target has both children, the code finds the in-order successor (smallest node in the right subtree) by going right once then left as far as possible. It copies the successor's value into the target node, then removes the successor node (which has at most one child) by updating its parent's pointer.

## Complexity

- **Time:** O(h)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-22 10:50 UTC
- Runtime: 32 ms
- Memory: 33.3 MB
- Language: C++
