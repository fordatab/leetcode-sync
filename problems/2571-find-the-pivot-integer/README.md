# Find the Pivot Integer

**Difficulty:** Easy
**Tags:** math, square-root, algebra

## Problem

Given a positive integer n (1 ≤ n ≤ 1000), find an integer x where the sum of integers from 1 to x equals the sum of integers from x to n. Both sums include x. Return x if it exists, otherwise return -1. At most one such pivot can exist for any given input.

## Approach

The solution uses a mathematical derivation rather than iteration. It computes `n*(n+1)/2` (the sum of 1 to n) and divides by 2 to get the target sum that each side should equal. Since the left sum is `x*(x+1)/2` and this must equal half the total, we get `x*(x+1)/2 = n*(n+1)/2 / 2`, which simplifies to `x² = n*(n+1)/2`. The code calculates `n*n + n` (equivalent to `n*(n+1)`), divides by 2, then takes the integer square root. If the square root squared equals the computed value exactly, then x is a perfect solution; otherwise no pivot exists and -1 is returned.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-30 07:24 UTC
- Runtime: 0 ms
- Memory: 7.6 MB
- Language: C++
