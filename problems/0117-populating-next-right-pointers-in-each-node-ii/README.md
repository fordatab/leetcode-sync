# Populating Next Right Pointers in Each Node II

**Difficulty:** Medium
**Tags:** tree, binary-tree, level-order-traversal, linked-list, constant-space

## Problem

Given a binary tree where each node has an additional 'next' pointer, connect each node to its immediate right neighbor at the same level. Nodes without a right neighbor should have their next pointer set to NULL. The tree can be any binary tree (not necessarily complete or perfect), with up to 6000 nodes having values between -100 and 100.

## Approach

The solution uses a level-order traversal approach with constant extra space by leveraging the next pointers that have already been established.

It maintains three key pointers: `current` traverses the current level using already-connected next pointers, `nextLevelStart` marks the first node of the next level, and `prev` tracks the last child encountered in the next level to connect subsequent children.

For each level, the algorithm iterates through nodes using their next pointers. For each node, it examines both left and right children. When a child exists, if it's the first child of the level, it becomes `nextLevelStart`; otherwise, it's linked from `prev`. The `prev` pointer is then updated to this child.

After finishing a level, the algorithm moves `current` to `nextLevelStart` and resets the tracking pointers to begin processing the next level. This continues until all levels are exhausted.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-11 23:52 UTC
- Runtime: 12 ms
- Memory: 18.5 MB
- Language: C++
