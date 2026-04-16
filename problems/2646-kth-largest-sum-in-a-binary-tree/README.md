# Kth Largest Sum in a Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, breadth-first-search, queue, sorting

## Problem

Given a binary tree and an integer k, compute the sum of node values at each level (nodes equidistant from the root). Return the kth largest among these level sums, or -1 if the tree has fewer than k levels. The tree contains between 2 and 100,000 nodes with values up to 1,000,000.

## Approach

The solution uses breadth-first search (BFS) with a queue to traverse the tree level by level. For each level, it processes all nodes currently in the queue, accumulating their values into a sum while enqueueing their children for the next level. Each level's sum is stored in a vector.

After computing all level sums, the vector is sorted in descending order using reverse iterators. The kth largest element is then accessed directly at index k-1 (using 0-based indexing). If k exceeds the number of levels in the tree, the function returns -1.

The key insight is that BFS naturally processes nodes level by level, making it straightforward to compute level sums, and sorting provides direct access to the kth largest value.

## Complexity

- **Time:** O(n + L log L)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-16 23:05 UTC
- Runtime: 67 ms
- Memory: 271.5 MB
- Language: C++
