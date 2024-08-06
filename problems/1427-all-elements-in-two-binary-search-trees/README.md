# All Elements in Two Binary Search Trees

**Difficulty:** Medium
**Tags:** binary-search-tree, tree-traversal, in-order-traversal, two-pointers, merge-sort

## Problem

Given two binary search trees, return a single sorted list containing all integer values from both trees in ascending order. Each tree can have 0 to 5000 nodes with values ranging from -100,000 to 100,000.

## Approach

The solution performs an in-order traversal on each BST separately to collect their elements into two sorted vectors. Since in-order traversal of a BST yields elements in sorted order, both `first` and `second` vectors are naturally sorted.

After collecting elements from both trees, the code merges the two sorted arrays using a reverse two-pointer technique. It starts from the end of both arrays (indices `i` and `j`) and fills the result array backwards from position `idx`. The `first` vector is resized to accommodate all elements from both trees.

During the merge, at each step it compares elements at positions `i` and `j`, placing the larger element at position `idx` and decrementing the appropriate pointer. When all elements from `second` are processed (j reaches -1), any remaining elements in `first` are already in their correct positions, so the merge is complete.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-06 03:31 UTC
- Runtime: 111 ms
- Memory: 83.9 MB
- Language: C++
