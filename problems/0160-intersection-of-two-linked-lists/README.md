# Intersection of Two Linked Lists

**Difficulty:** Easy
**Tags:** linked-list, two-pointers

## Problem

Given two singly linked lists, find and return the node where they merge (share the same physical node references), or null if they never intersect. The lists may have different lengths before the intersection point, and the combined structure is guaranteed to be acyclic. The lists can have up to 30,000 nodes each.

## Approach

The solution first counts the total length of both linked lists by traversing each one completely. It then aligns the starting positions by advancing the pointer of the longer list until both pointers are equidistant from their respective ends. After alignment, it advances both pointers simultaneously, comparing node references (not values) at each step. When the pointers point to the same node object, that node is the intersection point. If both pointers reach null without meeting, the lists don't intersect and null is returned. The alternating advancement in the final loop (using the modulo operation) is unnecessary since the lists are already aligned, but doesn't affect correctness.

## Complexity

- **Time:** O(m + n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 06:05 UTC
- Runtime: 40 ms
- Memory: 17.4 MB
- Language: C++
