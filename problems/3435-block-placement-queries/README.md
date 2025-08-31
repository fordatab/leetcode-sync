# Block Placement Queries

**Difficulty:** Hard
**Tags:** binary-search, ordered-set, interval-management, map, greedy

## Problem

Given an infinite number line starting at 0, process a sequence of queries that either place obstacles at specific positions or check whether a block of a given size can fit entirely within a range [0, x] without intersecting any existing obstacles. For placement queries, determine if there exists a contiguous gap large enough to accommodate the block where both the block and the gap end at or before position x.

## Approach

The solution maintains obstacles in a sorted set and tracks available spaces (gaps between consecutive obstacles) in a map indexed by space size, where each size maps to a set of starting positions for spaces of that size.

When placing an obstacle (query type 1), the code finds the gap containing the new obstacle position using binary search, removes that gap from the spaces map, and inserts two new smaller gaps on either side of the new obstacle.

For placement queries (query type 2), the code searches for gaps of sufficient size by iterating through the spaces map starting from the required block size. For each qualifying gap size, it checks only the leftmost starting position (since positions are sorted) to see if a block of the required size can fit and end at or before the maximum distance x.

The solution uses dummy obstacles at positions 0 and a calculated maximum distance to simplify boundary handling, ensuring there's always a containing gap for any inserted obstacle.

## Complexity

- **Time:** O(q log q)
- **Space:** O(q)

## Stats

- Submitted: 2025-08-31 06:48 UTC
- Runtime: 465 ms
- Memory: 367.2 MB
- Language: C++
