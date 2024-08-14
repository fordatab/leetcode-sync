# Double a Number Represented as a Linked List

**Difficulty:** Medium
**Tags:** linked-list, stack, math, two-pointer

## Problem

Given a singly linked list where each node contains a single digit (0-9) and the list as a whole represents a non-negative integer (most significant digit at the head), return the head of a linked list representing that number multiplied by 2. The list may contain up to 10,000 nodes and may not have leading zeros except when representing zero itself.

## Approach

The solution uses a stack to process the linked list in reverse order (from least significant to most significant digit). First, it creates a dummy node at the beginning and pushes all nodes (including the dummy) onto a stack. Then it pops nodes one by one, doubling each node's value and adding any carry from the previous digit. Each node's new value is set to the result modulo 10, and the carry is updated to the result divided by 10. Finally, if the dummy node has a non-zero value (meaning there was a final carry), the dummy becomes the new head; otherwise, the original head remains.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-14 01:17 UTC
- Runtime: 194 ms
- Memory: 128.6 MB
- Language: C++
