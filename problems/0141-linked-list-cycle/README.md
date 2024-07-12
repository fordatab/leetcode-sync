# Linked List Cycle

**Difficulty:** Easy
**Tags:** linked-list, two-pointers, cycle-detection, floyds-algorithm

## Problem

Given the head of a singly linked list, determine whether the list contains a cycle where some node's next pointer eventually points back to a previously visited node. The list may contain 0 to 10,000 nodes with values ranging from -100,000 to 100,000. The challenge asks for a solution using constant memory.

## Approach

This solution implements Floyd's cycle detection algorithm (also known as the tortoise and hare algorithm) using two pointers that move at different speeds.

The algorithm initializes both a slow pointer (`s`) and a fast pointer (`f`) at the head of the list. In each iteration, the fast pointer advances two steps while the slow pointer advances one step. The key insight is that if a cycle exists, the fast pointer will eventually catch up to the slow pointer inside the cycle, like a faster runner lapping a slower one on a circular track.

The code checks for null conditions carefully: it first handles an empty list, then in the loop it checks if the fast pointer can take two steps forward (by checking `f->next` and then checking if `f` becomes null after the double advance). If the pointers ever point to the same node, a cycle is detected. If the fast pointer reaches the end of the list (becomes null), no cycle exists.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-12 09:21 UTC
- Runtime: 11 ms
- Memory: 10.9 MB
- Language: C++
