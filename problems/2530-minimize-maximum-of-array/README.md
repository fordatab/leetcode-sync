# Minimize Maximum of Array

**Difficulty:** Medium
**Tags:** greedy, prefix-sum, array, math

## Problem

Given an array of non-negative integers, you can perform operations that transfer value from any element at index i (where i > 0 and nums[i] > 0) to the previous element at index i-1 by decrementing nums[i] and incrementing nums[i-1]. The goal is to find the minimum possible maximum value in the array after performing any number of such operations. The array has length n where 2 ≤ n ≤ 10^5, and each element can be as large as 10^9.

## Approach

The solution uses a greedy prefix-sum approach based on the insight that values can only flow leftward through the array. For each position i, we maintain a running prefix sum of all elements from index 0 to i.

The key observation is that the minimum achievable maximum value up to position i is determined by how evenly we can distribute the prefix sum across the first i+1 positions. This is computed as the ceiling of (prefixSum / (i+1)), which can be calculated using integer division as (prefixSum + i) / (i+1).

As we iterate through the array, we track the maximum of these calculated values across all prefixes. This maximum represents the minimum possible peak value we can achieve, since we can redistribute values within each prefix but cannot move values past the rightmost element of that prefix.

The algorithm runs in a single pass, updating the prefix sum at each step and computing the maximum distribution value needed for that prefix. The final answer is the largest such value encountered.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-07-14 06:09 UTC
- Runtime: 1 ms
- Memory: 75.2 MB
- Language: C++
