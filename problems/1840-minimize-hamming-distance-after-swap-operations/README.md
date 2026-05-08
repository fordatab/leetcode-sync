# Minimize Hamming Distance After Swap Operations

**Difficulty:** Medium
**Tags:** union-find, disjoint-set, graph, hash-table, greedy

## Problem

Given two integer arrays of length n and a list of allowed index swap pairs, find the minimum Hamming distance (number of positions where elements differ) between the source and target arrays after performing any number of swaps on the source array. The allowed swaps can be used multiple times and in any order, with array lengths up to 10^5.

## Approach

This solution uses **Union-Find (Disjoint Set Union)** to identify connected components of indices that can be freely rearranged through the allowed swaps.

1. Initialize a Union-Find structure with path compression and union by rank for efficiency.

2. Process all allowed swap pairs to build connected components - indices in the same component can have their elements rearranged arbitrarily through a sequence of swaps.

3. For each connected component, count the frequency of each value from the source array that belongs to that component, storing these counts in a nested hash map indexed by component root.

4. Iterate through the target array. For each position, find its component and try to match the target value with an available source value from the same component. If a match exists (count > 0), decrement the count; otherwise, increment the Hamming distance.

The key insight is that within each connected component, we can optimally match as many source values to target values as possible, and only the unmatched positions contribute to the final Hamming distance.

## Complexity

- **Time:** O(n + m * α(n))
- **Space:** O(n)

## Stats

- Submitted: 2026-05-08 20:41 UTC
- Runtime: 157 ms
- Memory: 154 MB
- Language: C++
