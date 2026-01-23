# Consecutive Numbers Sum

**Difficulty:** Hard
**Tags:** math, number-theory, iteration

## Problem

Given a positive integer n, determine how many distinct ways it can be expressed as the sum of consecutive positive integers. For instance, 9 can be written as 9 itself, 4+5, or 2+3+4, yielding three different representations. The constraint allows n up to one billion.

## Approach

The solution uses a mathematical insight: if n can be written as a sum of k consecutive integers starting from some value x, then n = x + (x+1) + ... + (x+k-1) = k*x + k*(k-1)/2. Rearranging gives x = (n - k*(k-1)/2) / k, which must be a positive integer.

The code iterates through possible sequence lengths k starting from 2 (since k=1 is always valid and counted initially). For each k, it checks whether (N - k*(k-1)/2) is divisible by k, which ensures x is an integer. The loop continues while k < sqrt(2*N), derived from the constraint that x must be positive: n - k*(k-1)/2 > 0, which simplifies to k < sqrt(2*n) approximately.

The algorithm counts how many valid sequence lengths exist by testing the divisibility condition for each k. It initializes count to 1 to account for n itself (the trivial case of a single number).

## Complexity

- **Time:** O(sqrt(n))
- **Space:** O(1)

## Stats

- Submitted: 2026-01-23 03:36 UTC
- Runtime: 3 ms
- Memory: 7.8 MB
- Language: C++
