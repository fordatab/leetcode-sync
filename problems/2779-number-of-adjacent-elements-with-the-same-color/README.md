# Number of Adjacent Elements With the Same Color

**Difficulty:** Medium
**Tags:** array, simulation, incremental-update

## Problem

Given an array of length n initially filled with zeros (uncolored), process a sequence of queries where each query colors a specific index with a given color. After each query, count the total number of adjacent pairs in the array that have the same non-zero color. The constraints allow up to 100,000 elements and 100,000 queries, with color values up to 100,000.

## Approach

The solution maintains a running count of matching adjacent pairs and incrementally updates it for each query. When coloring an index, it first checks if that position was previously colored (non-zero). If so, it removes the contribution of the old color by checking if it matched its left and/or right neighbors, decrementing the count accordingly. Then it adds the contribution of the new color by checking if the new color matches the left and/or right neighbors (if they exist and are non-zero), incrementing the count. The array is updated with the new color, and the current count is stored in the result array. This avoids recounting all pairs from scratch after each query.

## Complexity

- **Time:** O(q)
- **Space:** O(n + q)

## Stats

- Submitted: 2025-09-02 04:40 UTC
- Runtime: 100 ms
- Memory: 199.8 MB
- Language: C++
