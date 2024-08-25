# Pow(x, n)

**Difficulty:** Medium
**Tags:** recursion, divide-and-conquer, math, exponentiation-by-squaring

## Problem

The task is to compute x raised to the power n, where x is a floating-point number between -100 and 100, and n is an integer that can range from -2^31 to 2^31-1. The exponent can be negative, requiring the result to be the reciprocal of x raised to the absolute value of n. The implementation must handle edge cases like zero base or zero exponent efficiently.

## Approach

The solution uses **divide-and-conquer exponentiation** (also known as exponentiation by squaring). The main function handles edge cases: if x is zero it returns 0, if n is zero it returns 1. It converts n to its absolute value as a long (to handle the INT_MIN edge case where abs(INT_MIN) overflows a signed int), then calls a recursive helper function.

The recursive `dnc` function implements the core algorithm: it computes x^(n/2) recursively, then squares that result. If n is odd, it multiplies by an additional x. This approach reduces the number of multiplications from O(n) to O(log n) by halving the exponent at each step.

After computing the result for the absolute value of n, the main function checks the sign of the original exponent. If n was negative, it returns the reciprocal (1/res); otherwise, it returns res directly.

## Complexity

- **Time:** O(log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-25 02:38 UTC
- Runtime: 0 ms
- Memory: 8.3 MB
- Language: C++
