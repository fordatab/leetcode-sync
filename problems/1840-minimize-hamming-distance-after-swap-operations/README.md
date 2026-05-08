# Minimize Hamming Distance After Swap Operations

**Difficulty:** Medium
**Tags:** union-find, disjoint-set, hash-table, greedy, graph-connectivity

## Problem

Given two arrays of equal length and a list of index pairs representing allowed swaps, determine the minimum Hamming distance (number of differing positions) achievable by performing any sequence of allowed swaps on the source array. Swaps can be performed multiple times and in any order. Arrays can have up to 10^5 elements with values up to 10^5, and there can be up to 10^5 allowed swap pairs.

## Approach

The solution uses a Union-Find (Disjoint Set Union) data structure to group indices that can reach each other through swaps. Since swaps are transitive (if index i can swap with j, and j with k, then effectively i can reach k), indices form connected components.

First, it builds the union-find structure with path compression and union by rank optimizations. For each allowed swap pair, it unions the two indices into the same component.

Next, it creates a nested hashmap where the outer key is the component root, and the inner map counts the frequency of each value in the source array within that component. This represents the "pool" of values available in each component.

Finally, it iterates through each target position. For each target value, it checks if that value is available in the corresponding component's pool (the component containing that index). If available, it decrements the count (matching that position); otherwise, it increments the Hamming distance counter. This greedy matching works because within each component, values can be arbitrarily rearranged to minimize mismatches.

## Complexity

- **Time:** O(n + m * α(n))
- **Space:** O(n)

## Stats

- Submitted: 2026-05-08 20:49 UTC
- Runtime: 143 ms
- Memory: 154 MB
- Language: C++
