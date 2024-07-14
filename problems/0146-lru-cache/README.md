# LRU Cache

**Difficulty:** Medium
**Tags:** hash-table, linked-list, doubly-linked-list, design, lru-cache

## Problem

Design a cache that stores key-value pairs with a maximum capacity and evicts the least recently used item when the capacity is exceeded. The cache must support retrieving values by key and inserting or updating key-value pairs, both in constant average time. When an item is accessed or inserted, it becomes the most recently used.

## Approach

The solution uses a doubly-linked list combined with a hash map to achieve O(1) operations. The hash map stores keys mapped to pointers of nodes in the doubly-linked list, enabling constant-time lookups. The doubly-linked list maintains access order, with dummy sentinel nodes (left and right) marking the boundaries. The least recently used items are near the left sentinel, while the most recently used items are near the right sentinel.

For `get` operations, if the key exists in the hash map, the corresponding node is removed from its current position in the list and reinserted at the end (right side) to mark it as most recently used. For `put` operations, if the key already exists, its node is removed from the list first. A new node is then created and inserted at the end. If the cache size exceeds capacity after insertion, the least recently used node (immediately after the left sentinel) is removed from both the list and the hash map.

The `remove` helper unlinks a node from the doubly-linked list by updating the prev and next pointers of its neighbors. The `insert` helper places a node immediately before the right sentinel, making it the most recently used item.

## Complexity

- **Time:** O(1)
- **Space:** O(capacity)

## Stats

- Submitted: 2024-07-14 23:06 UTC
- Runtime: 330 ms
- Memory: 174.9 MB
- Language: C++
