# Design HashSet

**Difficulty:** Easy
**Tags:** array, hash-set, direct-addressing, design

## Problem

Implement a hash set data structure from scratch that supports add, remove, and contains operations. Keys are integers in the range [0, 10^6], and the implementation cannot use built-in hash table libraries. Up to 10^4 operations will be performed.

## Approach

This solution uses direct address indexing with a large static array as the underlying storage. Instead of implementing a proper hash table with buckets and collision handling, it allocates an array of size 10,000,001 (covering all possible key values from 0 to 10^6). Each array index corresponds directly to a key value, storing 1 if the key is present and 0 if absent.

The `add` operation sets the array element at index `key` to 1. The `remove` operation decrements the value if it's non-zero (treating the count like a flag). The `contains` operation checks whether the value at index `key` is greater than 0.

This approach trades space for simplicity and constant-time operations, as all lookups are direct array accesses without any hashing or collision resolution needed.

## Complexity

- **Time:** O(1)
- **Space:** O(10^6)

## Stats

- Submitted: 2024-07-19 08:51 UTC
- Runtime: 171 ms
- Memory: 345.3 MB
- Language: C++
