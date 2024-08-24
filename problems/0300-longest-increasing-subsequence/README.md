# Longest Increasing Subsequence

**Difficulty:** Medium
**Tags:** dynamic-programming, array, subsequence

## Problem

Given an array of integers, find the length of the longest subsequence where elements appear in strictly increasing order. The subsequence doesn't need to be contiguous. The array can contain up to 2500 elements with values ranging from -10⁴ to 10⁴.

## Approach

This solution uses dynamic programming with a backward pass through the array. It maintains a `dp` array where `dp[i]` represents the length of the longest increasing subsequence starting at index `i`.

The algorithm iterates from right to left (from the end of the array). For each position `x`, it examines all subsequent positions `y` and checks if `nums[x] < nums[y]`. When this condition holds, it means we can extend the subsequence starting at `y` by prepending `nums[x]`, so we update `dp[x]` to be the maximum of its current value or `1 + dp[y]`.

Each position is initialized to 1 (representing a subsequence of just that element). After processing all positions, the answer is the maximum value in the `dp` array, since the longest increasing subsequence could start at any index.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-24 01:43 UTC
- Runtime: 72 ms
- Memory: 13.2 MB
- Language: C++
