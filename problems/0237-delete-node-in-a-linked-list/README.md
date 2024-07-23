# Delete Node in a Linked List

**Difficulty:** Medium
**Tags:** linked-list, pointers

## Problem

Given a reference to a specific node in a singly-linked list (but not the head), remove that node from the list. The node is guaranteed not to be the tail, all values are unique, and the list contains between 2 and 1000 nodes with values ranging from -1000 to 1000. The challenge is that you only have access to the node to delete, not the previous node or the head.

## Approach

Since we cannot access the previous node to update its `next` pointer, the solution employs a clever workaround: instead of removing the current node itself, we copy the value from the next node into the current node, then bypass the next node by updating the current node's `next` pointer to skip over it. This effectively "deletes" the current node's value from the list while only modifying the node we have access to.

The implementation is straightforward:
- Copy `node->next->val` into `node->val` (overwriting the current value)
- Update `node->next` to point to `node->next->next` (bypassing the next node)

This creates the illusion that the current node was deleted, when in reality we've deleted the next node and transplanted its value backward.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 22:30 UTC
- Runtime: 7 ms
- Memory: 12.7 MB
- Language: C++
