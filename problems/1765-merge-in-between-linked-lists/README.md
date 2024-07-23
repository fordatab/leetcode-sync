# Merge In Between Linked Lists

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, pointer-manipulation

## Problem

Given two linked lists list1 and list2, remove nodes from position a to position b (inclusive, 0-indexed) in list1 and insert the entire list2 in their place. The constraints guarantee that a and b are valid positions within list1 (with a ≤ b < list1.length - 1), and both lists have at least the minimum required lengths.

## Approach

The solution uses a single-pass traversal to locate the critical connection points. It maintains a counter starting at 1 and walks through list1, identifying two key nodes: the node at position a (stored as `first`) which will become the predecessor to list2, and the node at position b+1 (stored as `last`) which will be the successor after list2. After the traversal, it connects `first->next` to the head of list2, then traverses to the end of list2, and finally connects that end node to `last`. This effectively splices list2 into the gap created by removing nodes a through b from list1. The original head of list1 is preserved and returned.

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 22:20 UTC
- Runtime: 201 ms
- Memory: 99.6 MB
- Language: C++
