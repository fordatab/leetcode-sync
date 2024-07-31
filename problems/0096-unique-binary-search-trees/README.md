# Unique Binary Search Trees

**Difficulty:** Medium
**Tags:** dynamic-programming, binary-search-tree, catalan-numbers, lookup-table, math

## Problem

Given an integer n, count how many structurally distinct binary search trees can be formed using exactly n nodes with values from 1 to n. Each tree must satisfy the BST property where left subtree values are smaller and right subtree values are larger than the root. The constraint is 1 ≤ n ≤ 19.

## Approach

This solution uses a precomputed lookup table containing the first 19 Catalan numbers. The number of unique BSTs with n nodes equals the (n-1)th Catalan number, since the count follows the recursive formula where each value can be the root, with smaller values forming the left subtree and larger values forming the right subtree. The Catalan sequence (1, 2, 5, 14, 42, ...) is stored in a constant array, and the solution simply returns `catalan[n-1]` for the given input. This avoids any computation at runtime by trading off a small amount of memory for constant-time lookups.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-31 02:39 UTC
- Runtime: 2 ms
- Memory: 7.3 MB
- Language: C++
