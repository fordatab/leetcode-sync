# Find the Prefix Common Array of Two Arrays

**Difficulty:** Medium
**Tags:** hash-set, prefix-sum, array, counting

## Problem

Given two permutations A and B of integers from 1 to n, construct an array C where C[i] represents the count of numbers that appear in both A[0..i] and B[0..i]. The arrays are 0-indexed and have equal length n (1 ≤ n ≤ 50).

## Approach

The solution maintains two hash sets (`ctA` and `ctB`) to track which numbers have been seen so far in arrays A and B respectively. At each index i, it inserts A[i] into `ctA` and B[i] into `ctB`. To update the common count, it checks:

1. If B[i] already exists in `ctA` (meaning B[i] was seen earlier in A), increment the counter
2. If A[i] already exists in `ctB` (meaning A[i] was seen earlier in B), increment the counter
3. If A[i] equals B[i], decrement the counter to avoid double-counting the same element

This incremental approach avoids recounting all common elements at each step by only examining the two newly added elements and adjusting the running count accordingly.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-06-02 20:32 UTC
- Runtime: 12 ms
- Memory: 90.5 MB
- Language: C++
