# Find the Number of Good Pairs I

**Difficulty:** Easy
**Tags:** array, brute-force, math, nested-loops

## Problem

Given two integer arrays nums1 and nums2 of lengths n and m respectively, and a positive integer k, count the number of index pairs (i, j) where nums1[i] is divisible by nums2[j] * k. The arrays have maximum length 50, and all values are in the range [1, 50].

## Approach

The solution uses a brute-force nested loop approach. For each element in nums1, it iterates through every element in nums2, computes the divisor as nums2[j] * k, and checks if nums1[i] is divisible by this value using the modulo operator. Each time the divisibility condition is satisfied (nums1[i] % div == 0), the answer counter is incremented. Finally, the total count of valid pairs is returned.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-24 00:49 UTC
- Runtime: 8 ms
- Memory: 41.9 MB
- Language: C++
