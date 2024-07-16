# N-ary Tree Level Order Traversal

**Difficulty:** Medium
**Tags:** breadth-first-search, tree, queue, level-order-traversal

## Problem

Given the root of an n-ary tree where each node can have any number of children, return the values of all nodes organized by their depth level. The tree can have up to 10,000 nodes and a maximum height of 1000. An empty tree should return an empty result.

## Approach

This solution uses breadth-first search (BFS) with a queue to traverse the tree level by level. Starting with the root in the queue, it processes each level completely before moving to the next. For each level, it captures the current queue size to know how many nodes belong to that level, then iterates exactly that many times. During each iteration, it dequeues a node, adds its value to the current level's result vector, and enqueues all of its children for processing in the next level. Once all nodes at the current level are processed, the level's values are added to the output. This continues until the queue is empty, meaning all levels have been traversed.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-16 23:58 UTC
- Runtime: 13 ms
- Memory: 15.7 MB
- Language: C++
