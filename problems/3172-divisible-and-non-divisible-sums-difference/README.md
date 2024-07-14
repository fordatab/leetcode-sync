# Divisible and Non-divisible Sums Difference

**Difficulty:** Easy
**Tags:** math, arithmetic-series, number-theory

## Problem

Given two positive integers n and m (both between 1 and 1000), compute the difference between two sums: the sum of all integers from 1 to n that are not divisible by m, minus the sum of all integers from 1 to n that are divisible by m. The result can be positive, negative, or zero depending on the values of n and m.

## Approach

The solution uses arithmetic series formulas to avoid iterating through the range. First, it calculates the sum of all integers from 1 to n using the formula `n*(n+1)/2`. Then it determines how many multiples of m exist in the range [1, n] by computing `a = n/m` (integer division). The sum of these multiples forms an arithmetic series: m, 2m, 3m, ..., am, which equals `m*(1 + 2 + ... + a) = m*a*(a+1)/2`. Since the total sum equals (sum of non-divisibles) + (sum of divisibles), and we want (sum of non-divisibles) - (sum of divisibles), we can rewrite this as: total - 2*(sum of divisibles). This gives us `t - 2*j` where t is the total sum and j is the sum of multiples of m.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:37 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
