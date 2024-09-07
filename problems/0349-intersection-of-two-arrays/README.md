# Intersection of Two Arrays

**Difficulty:** Easy
**Tags:** hash-table, set, array, two-pointers

## Problem

Given two integer arrays, find all unique elements that appear in both arrays and return them in any order. Each array can contain up to 1000 elements with values ranging from 0 to 1000, and duplicates within each array should be ignored in the result.

## Approach

The solution uses two hash sets to eliminate duplicates from each input array. First, it constructs an unordered_set from nums1 containing all unique elements from the first array. Then it creates another unordered_set from nums2 for the second array. The algorithm iterates through all elements in the first set and checks if each element exists in the second set using a lookup operation. When a match is found (an element present in both sets), it's added to the output vector. This effectively finds the set intersection while maintaining uniqueness.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-09-07 10:15 UTC
- Runtime: 6 ms
- Memory: 14.5 MB
- Language: C++
