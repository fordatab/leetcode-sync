# Two Sum IV - Input is a BST

**Difficulty:** Easy
**Tags:** binary-search-tree, two-pointers, tree-traversal, stack, iterator

## Problem

Given a binary search tree and a target integer k, determine whether any two distinct nodes in the tree have values that sum to k. The tree can contain up to 10,000 nodes with values ranging from -10,000 to 10,000, and k can range from -100,000 to 100,000.

## Approach

This solution implements a two-pointer technique on a BST using custom iterators. It creates two `BSTIterator` instances: one that traverses the tree in ascending order (in-order traversal) and another in descending order (reverse in-order traversal).

The iterators use stacks to maintain their position in the tree. The forward iterator (`in`) pushes all left children onto the stack, while the reverse iterator (`rev`) pushes all right children. When advancing, each iterator pops the current node, processes it, and then pushes the appropriate children for the next iteration.

The main algorithm initializes two pointers: `i` at the smallest value and `j` at the largest value. It then uses a two-pointer approach: if the sum equals k, it returns true; if the sum is too large, it moves the right pointer left (decreasing the sum); if too small, it moves the left pointer right (increasing the sum). This continues until the pointers meet or cross.

The key insight is that by treating the BST as a sorted array through these bidirectional iterators, we can apply the classic two-pointer technique for finding pair sums in sorted data, while maintaining O(h) space complexity where h is the tree height.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-03 01:20 UTC
- Runtime: 34 ms
- Memory: 36 MB
- Language: C++
