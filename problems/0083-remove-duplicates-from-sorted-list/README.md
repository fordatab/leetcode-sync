# Remove Duplicates from Sorted List

**Difficulty:** Easy
**Tags:** linked-list, two-pointers, iteration

## Problem

Given the head of a singly linked list sorted in ascending order, remove all duplicate nodes so that each distinct value appears exactly once. The list can contain 0 to 300 nodes with values between -100 and 100. Return the modified list, which must remain sorted.

## Approach

The solution uses a two-pointer technique to traverse the sorted linked list. It maintains a pointer `a` to preserve the original head, then iterates through the list with `head`. For each node, it uses an inner loop with pointer `next` to skip over all consecutive nodes that have the same value as the current node. Once all duplicates are found, it updates `head->next` to point directly to the first node with a different value (or null if no such node exists), effectively removing all duplicate nodes in between. The outer loop then advances to the next distinct node and repeats the process until the end of the list is reached.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 06:50 UTC
- Runtime: 6 ms
- Memory: 16.5 MB
- Language: C++
