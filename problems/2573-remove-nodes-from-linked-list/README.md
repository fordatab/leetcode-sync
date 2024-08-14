# Remove Nodes From Linked List

**Difficulty:** Medium
**Tags:** linked-list, stack, monotonic-stack

## Problem

Given a singly linked list, remove every node that has a node with a strictly greater value anywhere to its right. The list can contain up to 100,000 nodes with values ranging from 1 to 100,000. Return the head of the modified list containing only nodes that are not smaller than any node to their right.

## Approach

The solution uses a stack-based approach to process the linked list from right to left. It first pushes all nodes (including a dummy head) onto a stack, effectively reversing the traversal order. Then it pops nodes one by one, maintaining a `prev` pointer to track the rightmost node seen so far.

As nodes are popped from the stack, the algorithm compares each node's value with `prev->val`. If the current node's value is smaller than `prev->val`, it means this node should be removed, so the algorithm updates the next pointer of the node still on top of the stack to skip over the current node and point directly to `prev`. Otherwise, the current node becomes the new `prev` since it's not dominated by anything to its right.

This effectively filters out nodes that have a greater-valued node to their right, rebuilding the linked list connections as it processes nodes from right to left. The dummy node ensures proper handling of the head, and the final result is returned via `dummy.next`.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-14 01:56 UTC
- Runtime: 294 ms
- Memory: 173.2 MB
- Language: C++
