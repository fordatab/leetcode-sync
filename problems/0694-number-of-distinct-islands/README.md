# Number of Distinct Islands

**Difficulty:** Medium
**Tags:** depth-first-search, matrix, hash-set, graph-traversal, coordinate-normalization

## Problem

Given an m×n binary grid where 1s represent land cells forming islands (connected 4-directionally), count how many distinct island shapes exist. Two islands are considered the same if one can be translated (shifted) to match the other, but rotation and reflection don't count as equivalence. The grid dimensions are at most 50×50.

## Approach

The solution uses depth-first search to explore each island and normalize its shape by recording relative coordinates. For each unvisited land cell, it initiates a DFS that marks cells as visited (by setting them to 0) and records each cell's position relative to the starting cell as a pair (m-i, n-j). This creates a translation-invariant signature for the island shape. All island signatures are collected in a set of vectors, which automatically deduplicates identical shapes. The final answer is the size of this set, representing the number of unique island configurations.

## Complexity

- **Time:** O(m × n)
- **Space:** O(m × n)

## Stats

- Submitted: 2025-08-31 01:43 UTC
- Runtime: 7 ms
- Memory: 36.9 MB
- Language: C++
