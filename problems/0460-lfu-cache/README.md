# LFU Cache

**Difficulty:** Hard
**Tags:** hash-table, linked-list, design, lfu-cache

## Problem

Design a cache that evicts entries based on access frequency, where each key tracks how many times it has been accessed. When the cache is full and a new key must be inserted, remove the key with the lowest access count; if multiple keys share the minimum count, evict the one that was least recently used among them. Both retrieval and insertion operations must run in constant average time.

## Approach

The solution maintains three hash maps and a frequency counter. `m_values` stores each key's value and an iterator pointing into a frequency list. `m_counts` tracks the current access count for each key. `m_countKeyMap` maps each frequency level to a doubly-linked list of keys at that frequency, ordered from most-recently-used at the front to least-recently-used at the back. `m_lowestFrequency` tracks the minimum frequency present in the cache.

On `get`, if the key exists, it calls `put` with the existing value to increment the frequency, then returns the value. On `put`, if inserting a new key and the cache is full, it removes the back element (LRU) from the list at `m_lowestFrequency`. For both new and existing keys, the code removes the key from its current frequency list, increments its count, and pushes it to the front of the next frequency list. When a frequency list becomes empty, it's erased from the map, and if that was the lowest frequency, `m_lowestFrequency` is incremented.

The iterator stored in each `Node` allows O(1) removal from the middle of a list when a key's frequency changes. The front-to-back ordering of each frequency list naturally maintains LRU ordering, so eviction simply pops from the back of the lowest-frequency list.

## Complexity

- **Time:** O(1)
- **Space:** O(capacity)

## Stats

- Submitted: 2026-01-19 09:44 UTC
- Runtime: 131 ms
- Memory: 193 MB
- Language: C++
