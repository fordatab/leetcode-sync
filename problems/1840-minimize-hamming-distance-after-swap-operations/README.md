# Minimize Hamming Distance After Swap Operations

**Difficulty:** Medium
<<<<<<< HEAD
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
=======
**Tags:** union-find, disjoint-set, hash-table, greedy, graph-connectivity

## Problem

Given two arrays of equal length and a list of index pairs representing allowed swaps, determine the minimum Hamming distance (number of differing positions) achievable by performing any sequence of allowed swaps on the source array. Swaps can be performed multiple times and in any order. Arrays can have up to 10^5 elements with values up to 10^5, and there can be up to 10^5 allowed swap pairs.

## Approach

The solution uses a Union-Find (Disjoint Set Union) data structure to group indices that can reach each other through swaps. Since swaps are transitive (if index i can swap with j, and j with k, then effectively i can reach k), indices form connected components.

First, it builds the union-find structure with path compression and union by rank optimizations. For each allowed swap pair, it unions the two indices into the same component.

Next, it creates a nested hashmap where the outer key is the component root, and the inner map counts the frequency of each value in the source array within that component. This represents the "pool" of values available in each component.

Finally, it iterates through each target position. For each target value, it checks if that value is available in the corresponding component's pool (the component containing that index). If available, it decrements the count (matching that position); otherwise, it increments the Hamming distance counter. This greedy matching works because within each component, values can be arbitrarily rearranged to minimize mismatches.
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Complexity

- **Time:** O(n + m * α(n))
- **Space:** O(n)

## Stats

<<<<<<< HEAD
- Submitted: 2026-05-08 20:41 UTC
- Runtime: 157 ms
=======
- Submitted: 2026-05-08 20:49 UTC
- Runtime: 143 ms
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Memory: 154 MB
- Language: C++
