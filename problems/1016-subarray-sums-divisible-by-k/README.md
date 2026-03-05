# Subarray Sums Divisible by K

**Difficulty:** Medium
**Tags:** prefix-sum, hash-table, modular-arithmetic, array

## Problem

Given an array of integers and a divisor k, count how many contiguous subarrays have a sum that is divisible by k. The array can contain up to 30,000 elements with values ranging from -10,000 to 10,000, and k ranges from 2 to 10,000.

## Approach

The solution uses prefix sums combined with modular arithmetic and a hash map. It maintains a running prefix sum and computes its remainder modulo k at each position. The key insight is that two prefix sums with the same remainder modulo k indicate a subarray between them whose sum is divisible by k.

The hash map tracks how many times each remainder has been seen. Starting with remainder 0 counted once (representing an empty prefix), the algorithm processes each element by updating the prefix sum and normalizing negative remainders by adding k. For each position, it adds the count of previously seen matching remainders to the result (these form valid subarrays ending at the current position), then increments the count for the current remainder.

This approach avoids checking all possible subarrays explicitly, instead leveraging the mathematical property that (prefix[j] - prefix[i]) % k == 0 if and only if prefix[j] % k == prefix[i] % k.

## Complexity

- **Time:** O(n)
- **Space:** O(min(n, k))

## Stats

- Submitted: 2026-03-05 09:05 UTC
- Runtime: 9 ms
- Memory: 35.6 MB
- Language: C++
