# Combinations

**Difficulty:** Medium
**Tags:** backtracking, recursion, combinatorics, depth-first-search

## Problem

Given two integers n and k, generate all possible combinations of k distinct numbers selected from the range [1, n]. The combinations can be returned in any order, and each combination is represented as an unordered set (meaning [1,2] and [2,1] are considered identical). The constraints guarantee that n is at most 20 and k is at most n.

## Approach

The solution uses recursive backtracking to build all valid combinations. It maintains a current combination in the `arr` vector and explores all possibilities by iterating through numbers from `start` to `n`. At each recursive step, it adds a number to the current combination, recursively explores further with the next starting position (`x + 1` to ensure no duplicates and maintain order), and then removes the number (backtracks) to try the next option. When the current combination reaches size `k`, it's added to the result. The `start` parameter ensures that each combination only uses numbers greater than or equal to the last added number, preventing duplicate combinations and maintaining the unordered property.

## Complexity

- **Time:** O(C(n, k) * k)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-28 05:36 UTC
- Runtime: 95 ms
- Memory: 62 MB
- Language: C++
