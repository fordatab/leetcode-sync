# Sqrt(x)

**Difficulty:** Easy
**Tags:** math, linear-search

## Problem

Given a non-negative integer, compute its square root rounded down to the nearest integer without using built-in exponentiation functions. The input is constrained to be within the range of a 32-bit signed integer (0 to 2^31 - 1), and the result must also be non-negative.

## Approach

The solution uses a linear search approach to find the integer square root. It iterates from 0 up to 46340 (which is floor(sqrt(2^31 - 1))), checking each candidate value. For each candidate x, it computes x*x and compares it to the target value y. If x*x equals y exactly, it returns x immediately. If x*x exceeds y, it means the true square root lies between x-1 and x, so it returns x-1 (the floor value). The upper bound of 46340 is chosen because 46341^2 would overflow the range of possible inputs, so if the loop completes without finding a match, it returns 46340 as the maximum possible square root.

## Complexity

- **Time:** O(sqrt(n))
- **Space:** O(1)

## Stats

- Submitted: 2024-01-12 01:47 UTC
- Runtime: 9 ms
- Memory: 6.5 MB
- Language: C
