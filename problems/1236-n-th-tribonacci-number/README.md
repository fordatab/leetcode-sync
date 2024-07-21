# N-th Tribonacci Number

**Difficulty:** Easy
**Tags:** dynamic-programming, array, iteration, math

## Problem

Given an integer n between 0 and 37, compute the n-th term of the Tribonacci sequence, where each term is the sum of the previous three terms. The sequence starts with T₀ = 0, T₁ = 1, T₂ = 1, and each subsequent term T_n = T_(n-1) + T_(n-2) + T_(n-3). The result is guaranteed to fit in a 32-bit integer.

## Approach

The solution uses bottom-up dynamic programming with a simple array to store all Tribonacci values up to index n.

A vector `dp` of size n+3 is allocated to ensure there's always space for the base cases regardless of n's value. The first three positions are initialized with the base values: dp[0] = 0, dp[1] = 1, and dp[2] = 1.

The algorithm then iterates from index 3 to n (inclusive), computing each Tribonacci number as the sum of the three preceding values: dp[x] = dp[x-1] + dp[x-2] + dp[x-3]. This builds up the sequence iteratively until reaching the target index.

Finally, the value at dp[n] is returned as the answer. The extra space allocation (n+3 instead of n+1) handles edge cases where n is very small without requiring additional boundary checks.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-21 06:55 UTC
- Runtime: 3 ms
- Memory: 7.7 MB
- Language: C++
