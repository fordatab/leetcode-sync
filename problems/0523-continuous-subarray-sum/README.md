# Continuous Subarray Sum

**Difficulty:** Medium
**Tags:** prefix-sum, hash-table, modular-arithmetic, array

## Problem

Given an integer array and a divisor k, determine whether there exists a contiguous subarray of at least length 2 whose sum is divisible by k. The array can have up to 100,000 elements, with values up to 1 billion, and k can be up to 2^31 - 1.

## Approach

This solution uses prefix sum remainders with a hash map, but implements a two-pass approach. In the first pass, it computes the running prefix sum modulo k and stores each remainder's last occurrence index in a map. In the second pass, it again computes prefix sums modulo k and for each position checks if the map contains a matching remainder at an index that would create a subarray of length at least 2.

The key insight is that if two prefix sums have the same remainder when divided by k, the subarray between those positions has a sum divisible by k. The condition `pre[sum] - i > 0` verifies that the found position is ahead of the current position and creates a subarray of sufficient length.

The modulo operation is applied after each addition to keep numbers bounded and prevent overflow. The algorithm searches for positions where `prefix[j] ≡ prefix[i] (mod k)` with `j > i + 1`, which guarantees the subarray from index i+1 to j has a sum divisible by k.

## Complexity

- **Time:** O(n)
- **Space:** O(min(n, k))

## Stats

- Submitted: 2026-04-21 07:24 UTC
- Runtime: 97 ms
- Memory: 149.6 MB
- Language: C++
