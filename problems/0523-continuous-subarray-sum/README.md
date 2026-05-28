# Continuous Subarray Sum

**Difficulty:** Medium
**Tags:** prefix-sum, hash-table, modular-arithmetic, array

## Problem

<<<<<<< HEAD
Given an integer array and a divisor k, determine whether there exists a contiguous subarray of length at least 2 whose sum is a multiple of k. The array can have up to 100,000 elements, with values up to 10^9, and k can be up to 2^31 - 1. Zero is considered a multiple of any k.

## Approach

The solution computes a prefix sum array where each element stores the cumulative sum modulo k. It builds a hash map that stores all indices for each remainder value encountered. The code first checks if any prefix sum modulo k equals zero (which would indicate a valid subarray from index 0). Then it iterates through the array again, computing running sums modulo k, and for each remainder value, looks up previously seen indices with the same remainder in the hash map. If the distance between the current position and the last occurrence of that remainder is greater than 1, it means a valid subarray exists whose sum is divisible by k (since two positions with the same remainder indicate the subarray between them sums to a multiple of k).
=======
Given an integer array and a divisor k, determine whether there exists a contiguous subarray of at least length 2 whose sum is divisible by k. The array can have up to 100,000 elements, with values up to 1 billion, and k can be up to 2^31 - 1.

## Approach

This solution uses prefix sum remainders with a hash map, but implements a two-pass approach. In the first pass, it computes the running prefix sum modulo k and stores each remainder's last occurrence index in a map. In the second pass, it again computes prefix sums modulo k and for each position checks if the map contains a matching remainder at an index that would create a subarray of length at least 2.

The key insight is that if two prefix sums have the same remainder when divided by k, the subarray between those positions has a sum divisible by k. The condition `pre[sum] - i > 0` verifies that the found position is ahead of the current position and creates a subarray of sufficient length.

The modulo operation is applied after each addition to keep numbers bounded and prevent overflow. The algorithm searches for positions where `prefix[j] ≡ prefix[i] (mod k)` with `j > i + 1`, which guarantees the subarray from index i+1 to j has a sum divisible by k.
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Complexity

- **Time:** O(n)
<<<<<<< HEAD
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 07:19 UTC
- Runtime: 1015 ms
- Memory: 187.7 MB
=======
- **Space:** O(min(n, k))

## Stats

- Submitted: 2026-04-21 07:24 UTC
- Runtime: 97 ms
- Memory: 149.6 MB
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
