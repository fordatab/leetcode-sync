# Number of Zero-Filled Subarrays

**Difficulty:** Medium
**Tags:** array, two-pointers, sliding-window, math

## Problem

Given an integer array, count all contiguous subarrays that consist entirely of zeros. The array can contain up to 100,000 elements with values ranging from -10^9 to 10^9. A subarray must be non-empty and contiguous.

## Approach

The solution uses a two-pointer sliding window technique to identify consecutive sequences of zeros. It iterates through the array with pointer `r`, and when a zero is encountered, it sets `l` to the current position and expands `r` to include all consecutive zeros that follow. For each contiguous block of zeros of length `n`, the number of subarrays is calculated using the formula `n * (n + 1) / 2`, which represents the sum of integers from 1 to n (the number of ways to choose starting and ending positions within the block). The solution accumulates these counts across all zero-blocks and returns the total. The key insight is that a sequence of `k` consecutive zeros contributes `k + (k-1) + ... + 2 + 1` subarrays to the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-08-19 00:20 UTC
- Runtime: 0 ms
- Memory: 111.4 MB
- Language: C++
