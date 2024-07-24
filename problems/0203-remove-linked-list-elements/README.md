# Remove Linked List Elements

**Difficulty:** Easy
**Tags:** linked-list, recursion

## Problem

Given a singly linked list and a target value, remove all nodes whose value equals the target and return the modified list's head. The list can contain 0 to 10,000 nodes with values between 1 and 50, and the target value is also in the range 0 to 50.

## Approach

This solution uses recursion to traverse and rebuild the linked list from tail to head. For each node, it first recursively processes all nodes after it by calling `removeElements` on `head->next`, which returns the cleaned-up tail of the list. After recursion completes for the rest of the list, the current node's `next` pointer is updated to point to this cleaned tail. Finally, the function decides whether to keep or discard the current node: if the current node's value matches the target, it returns `head->next` (effectively removing the current node from the chain), otherwise it returns `head` itself (keeping the node). The base case handles null input by returning nullptr immediately.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 07:20 UTC
- Runtime: 23 ms
- Memory: 20.2 MB
- Language: C++
