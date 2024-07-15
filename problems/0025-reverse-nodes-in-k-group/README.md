# Reverse Nodes in k-Group

**Difficulty:** Hard
**Tags:** linked-list, two-pointers, recursion, pointer-manipulation

## Problem

Given a singly linked list and a positive integer k (where k is at most the list length), partition the list into consecutive groups of k nodes and reverse each complete group in-place. If the final group has fewer than k nodes, leave those nodes in their original order. The solution must rearrange node pointers without modifying node values.

## Approach

The solution uses a dummy node to simplify edge cases and employs a two-pointer technique to identify k-node segments. It first advances a `first` pointer k positions ahead of a `second` pointer to establish a k-width window. Then it iterates through the list: whenever `count` is a multiple of k, it has identified a complete k-node group between `second->next` and `first`. It temporarily disconnects this segment by setting `first->next` to nullptr, calls a standard iterative `reverseList` helper to reverse the segment in-place, then reconnects the reversed segment back into the main list by updating `second->next` to point to the new head (`first`, which became the tail after reversal) and the old head (`start`, which became the new tail) to point to `next`. Both pointers then advance one step, and the process repeats until all complete k-groups are reversed.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-15 03:48 UTC
- Runtime: 10 ms
- Memory: 16.5 MB
- Language: C++
