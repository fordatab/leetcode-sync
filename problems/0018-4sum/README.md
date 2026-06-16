# 4Sum

**Difficulty:** Medium
**Tags:** two-pointers, sorting, array, nested-loops

## Problem

Find all unique quadruplets in an array of integers that sum to a given target value. Each quadruplet must use four distinct indices, and the array can contain up to 200 elements with values ranging from -10^9 to 10^9. Duplicate quadruplets should not appear in the result.

## Approach

The solution uses a sorted array with nested loops and two pointers. First, it sorts the input array to enable duplicate skipping and two-pointer search. The outer two loops fix the first two elements (at indices i and j), then the inner portion uses a two-pointer technique on the remaining subarray to find pairs that complete the quadruplet. For each valid i and j, it calculates the remaining target sum needed and uses low/high pointers to find matching pairs. When a valid quadruplet is found, both pointers skip over duplicate values to avoid redundant results. After processing each j and i position, the loops also skip duplicate values at those positions to ensure uniqueness of quadruplets.

## Complexity

- **Time:** O(n^3)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-15 03:53 UTC
- Runtime: 14 ms
- Memory: 17.5 MB
- Language: C++
