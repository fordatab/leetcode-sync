# Linked List Cycle II

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, fast-slow-pointers, cycle-detection

## Problem

Given the head of a singly-linked list, determine if the list contains a cycle and, if so, return the node where the cycle begins. If no cycle exists, return null. The list can have up to 10,000 nodes with values ranging from -100,000 to 100,000. The solution must not modify the original list structure.

## Approach

The solution uses Floyd's cycle detection algorithm (tortoise and hare) with two phases:

**Phase 1 - Cycle Detection:** Two pointers traverse the list at different speeds: a slow pointer moves one step at a time while a fast pointer moves two steps. If they meet, a cycle exists. If the fast pointer reaches the end (null), there's no cycle.

**Phase 2 - Finding Cycle Start:** Once a meeting point is found, reset one pointer to the head while keeping the other at the meeting point. Move both pointers one step at a time; they will meet at the exact node where the cycle begins. This works due to the mathematical relationship between the distances traveled.

The algorithm returns the cycle start node if found, otherwise returns nullptr for acyclic lists or empty input.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-20 09:12 UTC
- Runtime: 9 ms
- Memory: 10.3 MB
- Language: C++
