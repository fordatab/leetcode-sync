# Fibonacci Number

**Difficulty:** Easy
**Tags:** recursion, math, fibonacci

## Problem

Given a non-negative integer n (where 0 ≤ n ≤ 30), compute the nth number in the Fibonacci sequence. The sequence starts with F(0) = 0 and F(1) = 1, and each subsequent number equals the sum of the previous two.

## Approach

This solution uses a naive recursive approach to compute Fibonacci numbers. The function has two base cases: it returns 0 when n is 0, and returns 1 when n is 1. For any other value of n, it recursively calls itself twice—once with (n-1) and once with (n-2)—and sums the results. This directly mirrors the mathematical definition of the Fibonacci sequence. However, this approach recomputes the same Fibonacci values multiple times, creating an exponential tree of recursive calls without any memoization or optimization.

## Complexity

- **Time:** O(2^n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-19 02:21 UTC
- Runtime: 15 ms
- Memory: 7.4 MB
- Language: C++
