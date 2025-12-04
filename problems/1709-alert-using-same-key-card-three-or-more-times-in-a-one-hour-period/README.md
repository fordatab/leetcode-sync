# Alert Using Same Key-Card Three or More Times in a One Hour Period

**Difficulty:** Medium
**Tags:** hash-table, sorting, sliding-window, string-parsing

## Problem

Given parallel arrays of worker names and access times (in HH:MM format) for keycard usage throughout a single day, identify which workers used their keycard three or more times within any one-hour window (60 minutes). Return the names of alerted workers in alphabetical order. Arrays can contain up to 100,000 entries, and each name-time pair is unique.

## Approach

The solution converts each time string to minutes since midnight (hours × 60 + minutes) for easier numerical comparison. It groups all access times by worker name using a hash map. For each worker, the times are sorted chronologically. Then a sliding window check examines every consecutive triplet of access times: if any triplet has the third time minus the first time ≤ 60 minutes, that worker triggers an alert. Finally, all alerted worker names are collected and sorted alphabetically before being returned.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-04 05:45 UTC
- Runtime: 99 ms
- Memory: 107.3 MB
- Language: C++
