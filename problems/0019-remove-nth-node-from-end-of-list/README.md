# Remove Nth Node From End of List

**Difficulty:** Medium
**Tags:** linked-list, two-pointers, dummy-node

## Problem

Given a singly linked list and an integer n, remove the node that is n positions from the end of the list and return the modified list's head. The list contains between 1 and 30 nodes with values from 0 to 100, and n is guaranteed to be valid (between 1 and the list size).

## Approach

The solution uses a two-pointer technique with a dummy head node to handle edge cases. First, a dummy node is created and linked before the actual head. Two pointers are initialized: a right pointer starts at the head and advances n steps forward, while a left pointer starts at the dummy node. Then both pointers advance together until the right pointer reaches the end of the list. At this point, the left pointer is positioned just before the node to be removed. The removal is performed by updating the left pointer's next reference to skip over the target node. Finally, the dummy's next pointer is returned as the new head, which elegantly handles the case where the original head itself needs to be removed.

## Complexity

- **Time:** O(sz)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-12 07:33 UTC
- Runtime: 0 ms
- Memory: 14.8 MB
- Language: C++
