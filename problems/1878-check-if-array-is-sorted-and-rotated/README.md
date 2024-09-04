# Check if Array Is Sorted and Rotated

**Difficulty:** Easy
**Tags:** array, two-pass, cyclic-iteration, sorting-verification

## Problem

Given an array, determine whether it represents a sorted non-decreasing sequence that has been rotated by some number of positions (possibly zero). The array may contain duplicate values, and the length ranges from 1 to 100 with values between 1 and 100. A rotation means shifting elements cyclically, where position i in the rotated array comes from position (i+x) % length in the original array.

## Approach

The solution works by finding the rotation point where the sorted order breaks. It first scans through the array to locate the first position where an element is greater than its successor—this marks where the rotation occurred. If no such break is found, the rotation point defaults to 0 (no rotation). Then it performs a second pass starting from this rotation point, wrapping around using modulo arithmetic to verify that all consecutive pairs maintain non-decreasing order. If any pair violates this order, the array cannot be a rotated sorted array. The key insight is that a valid rotated sorted array has at most one "break" point where a larger element precedes a smaller one, and everything else must be non-decreasing when viewed cyclically.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-04 23:10 UTC
- Runtime: 4 ms
- Memory: 10.5 MB
- Language: C++
