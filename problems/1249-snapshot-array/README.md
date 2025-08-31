# Snapshot Array

**Difficulty:** Medium
**Tags:** array, binary-search, design, hash-table

## Problem

Design a data structure that maintains an array and supports snapshotting its state at different points in time. The structure must handle set operations to modify elements, snap operations to capture the current state and return a snapshot ID, and get operations to retrieve an element's value as it was at a specific snapshot. The array can have up to 50,000 elements, and there can be up to 50,000 total operations across all method calls.

## Approach

The solution uses a vector of vectors where each index maintains a history of changes as (snapshot_id, value) pairs. Each element tracks only the snapshots where it was modified, not every snapshot ever taken.

During initialization, every index is seeded with a (-1, 0) pair representing the initial state before any snapshots. When `set` is called, if the most recent change at that index occurred in the current snapshot (before `snap` is called), it updates that value in place; otherwise, it appends a new (current_snapshot_id, value) pair.

The `snap` operation simply increments and returns the snapshot counter without copying any data. For `get`, the code performs binary search (`upper_bound`) on the change history for the requested index to find the rightmost change with snapshot_id ≤ the requested snap_id, then returns that value. This works because the pairs are naturally sorted by snapshot_id as they're appended in order.

## Complexity

- **Time:** O(log s) per get, O(1) per set and snap
- **Space:** O(n + m)

## Stats

- Submitted: 2025-08-31 03:47 UTC
- Runtime: 79 ms
- Memory: 186.5 MB
- Language: C++
