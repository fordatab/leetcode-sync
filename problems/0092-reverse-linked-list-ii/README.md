# Reverse Linked List II

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, reversal

## Problem

Given a singly linked list and two positions (left and right, both 1-indexed), reverse only the nodes between those positions inclusive, then return the modified list. The list contains between 1 and 500 nodes with values in the range [-500, 500], and left is always less than or equal to right and both are valid positions within the list.

## Approach

The solution uses a dummy node to simplify edge cases when reversing from the head. It first traverses to find the node immediately before position `left` (stored as `prev`). Then it identifies the start node `s` at position `left` and the end node `f` at position `right` by advancing through the list. The sublist from `s` to `f` is temporarily detached by saving the node after `f` and setting `f->next` to null. A helper function reverses this detached sublist using the standard three-pointer iterative approach (prev, curr, next). Finally, the reversed sublist is reconnected: `prev->next` points to the new head of the reversed portion, and the original start node `s` (now the tail of the reversed portion) connects to the saved node after the original `f` position.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-08 02:19 UTC
- Runtime: 0 ms
- Memory: 10.4 MB
- Language: C++
