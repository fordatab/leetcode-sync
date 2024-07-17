# Middle of the Linked List

**Difficulty:** Easy
**Tags:** linked-list, two-pointers, fast-slow-pointers

## Problem

Given a singly linked list, find and return the middle node. When the list has an even number of nodes (two middle candidates), return the second of the two middle nodes. The list contains between 1 and 100 nodes with values ranging from 1 to 100.

## Approach

The solution uses the classic two-pointer (fast and slow) technique to find the middle node in a single pass. Two pointers start at the head: `fast` moves two nodes at a time while `slow` moves one node at a time. When `fast` reaches the end of the list (either `fast` becomes null or `fast->next` becomes null), `slow` will be positioned at the middle node. This works because by the time `fast` has traversed the entire list, `slow` has only traversed half of it. For even-length lists, this naturally returns the second middle node because `slow` advances one extra step after the first middle.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-17 01:14 UTC
- Runtime: 0 ms
- Memory: 9.2 MB
- Language: C++
