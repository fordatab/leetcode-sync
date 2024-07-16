# Delete the Middle Node of a Linked List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, fast-slow-pointers

## Problem

Given the head of a singly-linked list, remove the node at the middle position (using 0-based indexing where the middle is floor(n/2)) and return the modified list's head. The list can contain between 1 and 100,000 nodes, with node values ranging from 1 to 100,000.

## Approach

The solution uses the classic two-pointer (fast and slow) technique to locate the node before the middle. A dummy node is created pointing to the head to handle edge cases uniformly. The fast pointer advances two steps at a time while the slow pointer advances one step at a time, starting with slow at the dummy node and fast at the head.

When the fast pointer reaches the end (either null or the last node), the slow pointer will be positioned exactly one node before the middle node. This positioning is crucial because to delete a node in a singly-linked list, we need access to its predecessor.

The middle node is then removed by updating the slow pointer's next reference to skip over it (slow->next = slow->next->next). Special cases are handled upfront: an empty list or a single-node list both return nullptr since there's nothing left after removing the only/middle node.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-16 09:31 UTC
- Runtime: 612 ms
- Memory: 299.8 MB
- Language: C++
