# The Earliest Moment When Everyone Become Friends

**Difficulty:** Medium
**Tags:** union-find, graph, sorting, connected-components

## Problem

Given n people labeled 0 to n-1 and a list of friendship events with timestamps, determine the earliest time when all people become connected through direct or transitive friendships. Each event specifies a timestamp and two people who become friends at that moment. Return the earliest timestamp when everyone is acquainted (forming one connected component), or -1 if this never happens. Constraints include n up to 100, up to 10,000 events, and unique timestamps.

## Approach

The solution uses a **Union-Find (Disjoint Set Union)** data structure to track connected components as friendships form over time.

First, the friendship events are sorted by timestamp to process them chronologically. A parent array is initialized where each person starts as their own component, and a component counter tracks the number of separate groups (initially n).

The code implements path compression in the `find` operation and union-by-rank in the `unite` operation for efficiency. For each event in chronological order, it attempts to unite the two people. When a successful union occurs (the two people were in different components), the component count decreases by one.

The key insight is that everyone becomes acquainted exactly when the number of components reaches 1. At that moment, the current timestamp is returned. If all events are processed without reaching a single component, -1 is returned.

## Complexity

- **Time:** O(m log m + m α(n))
- **Space:** O(n)

## Stats

- Submitted: 2026-01-21 11:55 UTC
- Runtime: 0 ms
- Memory: 18.2 MB
- Language: C++
