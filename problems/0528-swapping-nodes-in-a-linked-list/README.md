# Swapping Nodes in a Linked List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers

## Problem

Given a singly linked list and an integer k (1-indexed), swap the values of the kth node from the beginning with the kth node from the end. The list has between 1 and 10^5 nodes, and k is guaranteed to be valid (1 ≤ k ≤ n). Node values range from 0 to 100.

## Approach

The solution uses a two-pointer technique to locate both target nodes in a single traversal. It initializes two counters: `l` starting at `(-k)+1` and `f` starting at 1. As it traverses the list with pointer `p`, it uses counter `f` to identify the kth node from the beginning (stored in `a`). Simultaneously, it uses counter `l` and pointer `prev` to track the kth node from the end: by starting `prev` at the head and only advancing it when `l > 0` (which happens after k-1 iterations), `prev` ends up pointing to the kth node from the end when the traversal completes. Once both nodes are identified, their values are swapped using a temporary variable, and the modified list head is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-23 05:16 UTC
- Runtime: 758 ms
- Memory: 185.2 MB
- Language: C++
