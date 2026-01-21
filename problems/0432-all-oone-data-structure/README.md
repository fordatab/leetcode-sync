# All O`one Data Structure

**Difficulty:** Hard
**Tags:** hash-table, doubly-linked-list, design, data-structure

## Problem

Design a data structure that tracks string counts and supports four operations: incrementing a key's count, decrementing a key's count (removing it if the count reaches zero), and retrieving any key with the maximum or minimum count. All operations must execute in O(1) average time complexity, with up to 50,000 total operations and keys consisting of lowercase letters up to length 10.

## Approach

The solution uses a doubly-linked list of nodes where each node represents a distinct frequency level and contains a set of all keys at that frequency. A hash map maintains the mapping from each key to its current frequency node.

For **increment operations**, the key is removed from its current frequency node and added to the next frequency node (freq+1). If no node exists for freq+1, a new node is created and inserted into the linked list. If the old node becomes empty, it is removed from the list.

For **decrement operations**, the key is removed from its current node and moved to the previous frequency node (freq-1), with similar logic for creating new nodes when needed. If the frequency drops to zero, the key is removed from the map entirely.

**Min/max queries** are answered by accessing the first node after the head dummy (minimum) or the last node before the tail dummy (maximum), returning any key from that node's set. The doubly-linked list structure with dummy head and tail sentinels ensures that all operations maintain O(1) time complexity by avoiding list traversal.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-21 23:32 UTC
- Runtime: 67 ms
- Memory: 93.6 MB
- Language: C++
