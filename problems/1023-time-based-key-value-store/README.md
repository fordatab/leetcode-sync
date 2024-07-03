# Time Based Key-Value Store

**Difficulty:** Medium
**Tags:** hash-table, binary-search, design, sorted-array

## Problem

Build a data structure that stores key-value pairs along with timestamps, where each key can have multiple values at different times. The get operation must return the value associated with the largest timestamp that doesn't exceed the query timestamp, or an empty string if no such value exists. Timestamps for a given key are guaranteed to arrive in strictly increasing order, and there can be up to 200,000 total operations.

## Approach

The solution uses a hash map where each key maps to a vector of (value, timestamp) pairs. Since timestamps arrive in strictly increasing order, each key's vector is automatically sorted by timestamp.

The `set` operation simply appends the new (value, timestamp) pair to the key's vector in O(1) time.

The `get` operation first checks if the key exists and if the earliest timestamp is valid. Then it performs binary search on the sorted vector to find the largest timestamp less than or equal to the query timestamp. The binary search maintains invariants: when a timestamp matches exactly, it returns that value immediately; when mid's timestamp exceeds the query, it searches the left half; otherwise it searches the right half. After the loop, `r` points to the largest valid timestamp, so it returns the value at index `r`.

## Complexity

- **Time:** O(log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-03 07:15 UTC
- Runtime: 333 ms
- Memory: 133.3 MB
- Language: C++
