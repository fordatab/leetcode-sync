# Next Greater Node In Linked List

**Difficulty:** Medium
**Tags:** linked-list, monotonic-stack, stack

## Problem

Given a singly linked list with n nodes, find for each node the value of the first subsequent node that has a strictly greater value. Return the results as an integer array where each element is the next greater value for the corresponding node, or 0 if no such node exists. The list can contain up to 10,000 nodes with values up to 10^9.

## Approach

The solution uses a monotonic stack to track unsolved nodes as it traverses the linked list. First, it counts the total nodes to pre-allocate the result vector. Then it iterates through the list once, maintaining a stack of (value, index) pairs. For each node, it pops all stack entries with smaller values and sets their corresponding result positions to the current node's value—these are nodes that finally found their next greater element. The current node is then pushed onto the stack. Nodes remaining in the stack after traversal have no next greater element, so their result positions remain 0 (the vector's default initialization).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-23 09:33 UTC
- Runtime: 71 ms
- Memory: 43.4 MB
- Language: C++
