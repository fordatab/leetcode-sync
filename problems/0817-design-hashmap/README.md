# Design HashMap

**Difficulty:** Easy
**Tags:** hash-table, linked-list, design, separate-chaining

## Problem

Design a hash map data structure that supports insertion, retrieval, and deletion of key-value pairs without using built-in hash table libraries. Keys and values are integers in the range [0, 10^6], and the implementation must handle up to 10^4 operations. The get operation should return -1 if the key is not found.

## Approach

The solution implements a hash map using separate chaining for collision resolution. It maintains an array of 1000 buckets, where each bucket is a linked list headed by a dummy node. The hash function is simple modulo 1000 arithmetic.

For the `put` operation, the code computes the hash index, traverses the linked list at that bucket to check if the key already exists, and either updates the existing value or appends a new node to the end of the chain.

The `get` operation follows a similar traversal pattern: it hashes the key, walks the linked list at that bucket, and returns the value if found, or -1 otherwise.

The `remove` operation traverses the chain to find the target key, then unlinks and deletes the node by updating the previous node's next pointer, properly managing memory to avoid leaks.

## Complexity

- **Time:** O(n/k) average per operation, where n is the number of elements and k=1000 is the number of buckets; worst case O(n) if all keys hash to the same bucket
- **Space:** O(k + n) where k=1000 buckets and n is the number of stored key-value pairs

## Stats

- Submitted: 2025-09-09 06:37 UTC
- Runtime: 29 ms
- Memory: 60.6 MB
- Language: C++
