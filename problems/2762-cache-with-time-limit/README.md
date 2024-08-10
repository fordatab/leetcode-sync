# Cache With Time Limit

**Difficulty:** Medium
**Tags:** hash-table, timer, object-oriented-design

## Problem

Implement a cache data structure that stores key-value pairs with expiration times. Each entry has a duration in milliseconds after which it becomes inaccessible. The cache must support setting entries (returning true if overwriting an unexpired key), retrieving values (returning -1 if expired or absent), and counting active entries. Keys and values can be up to 10^9, durations up to 1000ms, and there can be up to 100 operations with delays up to 1450ms.

## Approach

The solution uses a JavaScript `Map` to store cache entries, where each entry contains both the value and a reference to a `setTimeout` timer. When `set` is called, the code first checks if the key already exists using `has()`. If it does, the existing timeout is cleared with `clearTimeout()` to prevent premature deletion. A new entry is then stored with the value and a fresh timeout that will automatically delete the key after the specified duration. The `get` method simply checks for key existence and returns the stored value or -1. The `count` method leverages the Map's built-in `size` property to return the number of active (unexpired) entries, since expired entries are automatically removed by their timeouts.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 21:50 UTC
- Runtime: 59 ms
- Memory: 48.9 MB
- Language: JavaScript
