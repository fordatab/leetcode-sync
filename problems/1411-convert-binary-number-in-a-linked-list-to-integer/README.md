# Convert Binary Number in a Linked List to Integer

**Difficulty:** Easy
**Tags:** linked-list, bit-manipulation, math

## Problem

Given a singly-linked list where each node contains either 0 or 1, representing a binary number with the most significant bit at the head, convert this binary representation to its decimal equivalent. The list contains at most 30 nodes, guaranteeing the result fits within standard integer bounds.

## Approach

The solution traverses the linked list once from head to tail, building the decimal value iteratively. It initializes the result with the head's value, then for each subsequent node, it doubles the current result (equivalent to left-shifting in binary) and adds the current node's value if it's 1. This mimics the process of reading a binary number from left to right: each new digit means the previous value is shifted one position (multiplied by 2) and the new bit is added to the least significant position.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 22:26 UTC
- Runtime: 0 ms
- Memory: 10 MB
- Language: C++
