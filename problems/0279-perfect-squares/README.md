# Perfect Squares

**Difficulty:** Medium
**Tags:** dynamic-programming, math, number-theory

## Problem

Given a positive integer n (1 ≤ n ≤ 10,000), find the minimum number of perfect square integers (like 1, 4, 9, 16, etc.) that sum exactly to n. For instance, 12 can be expressed as 4+4+4 (three squares) and 13 as 4+9 (two squares).

## Approach

The solution uses bottom-up dynamic programming with a 1D array `dp` where `dp[i]` represents the minimum number of perfect squares needed to sum to `i`.

The base case sets `dp[0] = 0` (zero squares needed for zero) and `dp[1] = 1` (one square needed for one). For each value `x` from 2 to `n`, the code iterates through all perfect squares `y*y` that don't exceed `x`.

For each such square, it considers using that square and adding it to the optimal solution for the remainder (`x - y*y`), computing `dp[x-y*y] + 1`. The minimum across all such possibilities is stored in `dp[x]`.

This recurrence relation systematically builds up the answer by trying each valid perfect square as the "last" square in the sum, ensuring we find the minimum count by the time we reach `dp[n]`.

## Complexity

- **Time:** O(n * sqrt(n))
- **Space:** O(n)

## Stats

- Submitted: 2024-09-06 00:45 UTC
- Runtime: 41 ms
- Memory: 11.2 MB
- Language: C++
