# Minimum Genetic Mutation

**Difficulty:** Medium
**Tags:** breadth-first-search, graph, hash-table, string

## Problem

Given a starting 8-character gene string and a target gene string, find the minimum number of single-character mutations needed to transform the start into the target. Each intermediate mutation must exist in a provided gene bank of valid mutations. All gene strings use only the characters A, C, G, and T. The gene bank can have up to 10 entries, and if no valid mutation path exists, return -1.

## Approach

This solution uses BFS to find the shortest mutation path. It builds an adjacency list by creating wildcard patterns for each gene string—replacing each character position with '*' to group genes that differ by one character at that position. The start gene is added to the bank and used as the BFS starting point. During BFS, for each gene, all 8 wildcard patterns are generated, and neighbors sharing those patterns are explored. A visited set prevents revisiting genes. The BFS level counter tracks mutation count, and when the target gene is dequeued, the level minus one (since the start counts as level 0) is returned. If BFS completes without finding the target, -1 is returned.

## Complexity

- **Time:** O(n * m^2)
- **Space:** O(n * m)

## Stats

- Submitted: 2024-09-08 04:49 UTC
- Runtime: 3 ms
- Memory: 8.9 MB
- Language: C++
