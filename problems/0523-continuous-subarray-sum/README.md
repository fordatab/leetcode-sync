# Continuous Subarray Sum

**Difficulty:** Medium
**Tags:** prefix-sum, hash-table, modular-arithmetic, array

## Problem

Given an integer array and a divisor k, determine whether there exists a contiguous subarray of length at least 2 whose sum is a multiple of k. The array can have up to 100,000 elements, with values up to 10^9, and k can be up to 2^31 - 1. Zero is considered a multiple of any k.

## Approach

The solution computes a prefix sum array where each element stores the cumulative sum modulo k. It builds a hash map that stores all indices for each remainder value encountered. The code first checks if any prefix sum modulo k equals zero (which would indicate a valid subarray from index 0). Then it iterates through the array again, computing running sums modulo k, and for each remainder value, looks up previously seen indices with the same remainder in the hash map. If the distance between the current position and the last occurrence of that remainder is greater than 1, it means a valid subarray exists whose sum is divisible by k (since two positions with the same remainder indicate the subarray between them sums to a multiple of k).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 07:19 UTC
- Runtime: 1015 ms
- Memory: 187.7 MB
- Language: C++
