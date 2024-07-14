# Delete Nodes From Linked List Present in Array

**Difficulty:** Medium
**Tags:** linked-list, hash-table, set

## Problem

Given an array of integers and a singly-linked list, remove all nodes from the list whose values appear in the array and return the modified list's head. The array contains up to 100,000 unique integers, the list has up to 100,000 nodes with values in the range 1 to 100,000, and the input guarantees at least one node will remain after removal.

## Approach

The solution uses a hash set for efficient lookup of values to remove. First, it converts the input array into an `unordered_set` for O(1) average-case lookups. Then it creates a dummy head node to simplify list construction.

The algorithm traverses the original linked list once. For each node, it checks if the node's value exists in the set. If the value is not in the set (meaning it should be kept), it creates a new `ListNode` with that value and appends it to the result list being built. If the value is in the set, the node is skipped.

The result list is built by maintaining a pointer (`node`) that tracks the last node in the new list. When a value needs to be kept, a new node is allocated, linked to `node->next`, and `node` advances to this new node. Finally, the dummy node's `next` pointer references the head of the filtered list.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-14 03:03 UTC
- Runtime: 591 ms
- Memory: 272.2 MB
- Language: C++
