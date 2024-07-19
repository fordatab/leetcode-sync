# Find the Difference of Two Arrays

**Difficulty:** Easy
**Tags:** hash-set, array, set-difference

## Problem

Given two integer arrays, return a two-element list where the first element contains all unique integers from the first array that don't appear in the second array, and the second element contains all unique integers from the second array that don't appear in the first array. Each array can contain up to 1000 elements with values ranging from -1000 to 1000, and duplicates should be eliminated from the results.

## Approach

The solution uses two unordered hash sets to efficiently track unique elements and perform lookups. First, it converts both input arrays into sets (`s1` and `s2`) to automatically eliminate duplicates and enable constant-time membership testing. Then it iterates through the first set, checking each element against the second set—any element not found in `s2` is added to the first result list. Similarly, it iterates through the second set and adds elements not found in `s1` to the second result list. This set-based approach avoids nested loops and handles the uniqueness requirement naturally through the set data structure.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-19 19:17 UTC
- Runtime: 29 ms
- Memory: 36.6 MB
- Language: C++
