# Reverse Linked List

**Difficulty:** Easy
**Tags:** linked-list, two-pointers, iteration

## Problem

Given the head of a singly linked list, reverse the direction of all pointers so that the last node becomes the first and vice versa, then return the new head. The list can contain 0 to 5000 nodes with values ranging from -5000 to 5000.

## Approach

This solution uses an iterative approach with three pointers to reverse the list in-place. It maintains `prev` (initially null), `curr` (starting at head), and `tmp` (temporary storage). During each iteration, it saves the next node in `tmp`, redirects the current node's `next` pointer to point backward at `prev`, then advances both `prev` and `curr` forward. The loop continues until `curr` becomes null, at which point `prev` points to what was originally the last node and is now the new head of the reversed list.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-01 00:12 UTC
- Runtime: 0 ms
- Memory: 11.6 MB
- Language: C++
