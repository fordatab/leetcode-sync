# Subsets II

**Difficulty:** Medium
**Tags:** backtracking, recursion, array, sorting

## Problem

Given an array of integers that may include duplicate values, generate all possible subsets (the power set) without including duplicate subsets in the result. The array can have up to 10 elements with values ranging from -10 to 10.

## Approach

The solution uses backtracking with duplicate elimination. First, it sorts the input array to group duplicate elements together. The recursive backtracking function explores two branches at each position: one where the current element is included in the subset, and one where it's excluded.

The key insight for avoiding duplicate subsets is in the exclusion branch: after choosing not to include an element, the algorithm skips over all subsequent duplicate occurrences of that same element before making the next recursive call. This ensures that if we decide to skip a value, we skip all instances of it, preventing duplicate subsets from being generated.

The base case occurs when the starting index reaches the array size, at which point the current subset is added to the results. The algorithm systematically explores all valid combinations by either taking or skipping elements, with the duplicate-skipping logic ensuring uniqueness.

## Complexity

- **Time:** O(n * 2^n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 03:31 UTC
- Runtime: 0 ms
- Memory: 9 MB
- Language: C++
