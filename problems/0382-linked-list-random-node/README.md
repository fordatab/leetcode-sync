# Linked List Random Node

**Difficulty:** Medium
**Tags:** linked-list, reservoir-sampling, randomized, math

## Problem

Design a data structure that stores a singly linked list and supports retrieving a random node's value, where each node must have equal probability of being selected. The list can contain up to 10,000 nodes with values ranging from -10,000 to 10,000, and the getRandom operation may be called up to 10,000 times.

## Approach

The solution uses **reservoir sampling** to select a random node without needing to know the list length in advance or store all values. During initialization, it saves a reference to the head of the linked list.

In `getRandom()`, it traverses the entire list while maintaining a running count (`len`) starting at 1. For each node at position `i`, it generates a random number between 0 and `i-1`. If that random number equals 0 (probability 1/i), the current node's value replaces the result. This ensures that by the end of traversal, each of the `n` nodes has exactly a 1/n probability of being the final selection.

The algorithm requires no auxiliary storage beyond a few variables and works even when the list length is unknown, making it suitable for streaming scenarios or very large lists.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-29 07:36 UTC
- Runtime: 22 ms
- Memory: 21.4 MB
- Language: C++
