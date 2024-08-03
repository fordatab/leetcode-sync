# Average of Levels in Binary Tree

**Difficulty:** Easy
**Tags:** binary-tree, breadth-first-search, level-order-traversal, queue

## Problem

Given a binary tree, compute the average value of all nodes at each depth level and return these averages as an array, ordered from the root level downward. The tree can contain between 1 and 10,000 nodes with values ranging from -2^31 to 2^31 - 1, and answers within 10^-5 of the actual value are acceptable.

## Approach

The solution uses a level-order traversal (breadth-first search) with a queue. Starting from the root, it processes all nodes at each level before moving to the next level. For each level, it records the queue size to know how many nodes exist at that depth, then iterates exactly that many times, popping each node, accumulating its value into a running sum, and enqueueing its children. After processing all nodes at a level, it divides the accumulated sum by the count of nodes to get the average and appends it to the result vector. This process continues until the queue is empty, meaning all levels have been visited.

## Complexity

- **Time:** O(n)
- **Space:** O(w)

## Stats

- Submitted: 2024-08-03 01:46 UTC
- Runtime: 13 ms
- Memory: 22.5 MB
- Language: C++
