# Reorder List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, fast-slow-pointer, list-reversal

## Problem

Given the head of a singly linked list with up to 50,000 nodes, rearrange it so that nodes alternate between the start and end of the original list: the first node, then the last node, then the second node, then the second-to-last node, and so on. The reordering must be done by changing node pointers, not by modifying node values.

## Approach

The solution uses a three-step process:

1. **Find the middle**: Use the slow-fast pointer technique where slow advances one step and fast advances two steps. When fast reaches the end, slow points to the middle of the list.

2. **Reverse the second half**: Starting from the node after the middle, reverse the second half of the list in-place using a standard iterative reversal with prev and tmp pointers. The first half is disconnected by setting `slow->next = nullptr`.

3. **Merge the two halves**: Interleave nodes from the first half (starting at head) and the reversed second half by alternating pointers. At each step, temporarily store the next pointers from both halves, link first to second, link second to first's original next, then advance both pointers. The process continues until all nodes from the second half are merged.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 07:37 UTC
- Runtime: 26 ms
- Memory: 21.4 MB
- Language: C++
