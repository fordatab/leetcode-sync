# Detect Squares

**Difficulty:** Medium
**Tags:** hash-table, geometry, counting, design

## Problem

Design a data structure that maintains a stream of 2D points and supports two operations: adding points (including duplicates) and counting how many axis-aligned squares can be formed using a query point as one corner and three points from the data structure as the other corners. The squares must have positive area with edges parallel to the axes.

## Approach

The solution uses two data structures: a hash map (`ptsCount`) that tracks the frequency of each point using a combined key (x-coordinate shifted left 32 bits OR-ed with y-coordinate), and a vector (`pts`) that stores all added points.

For the `add` operation, each point is stored in both structures—its count is incremented in the hash map and the point itself is appended to the vector.

For the `count` operation, the code iterates through all stored points. For each point `(x, y)`, it checks if this point could be diagonally opposite to the query point `(px, py)` in a square by verifying that `|px - x| == |py - y|` (equal side lengths) and that the points are neither horizontally nor vertically aligned. If valid, it looks up the counts of the two remaining corner points at `(x, py)` and `(px, y)`, multiplies them together (to account for all combinations), and adds to the result.

The key insight is that for any diagonal pair of opposite corners in an axis-aligned square, the other two corners are uniquely determined and can be looked up directly in the hash map.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-25 04:21 UTC
- Runtime: 218 ms
- Memory: 100.2 MB
- Language: C++
