# Harshad Number

**Difficulty:** Easy
**Tags:** math, number-theory, digit-manipulation

## Problem

Given an integer x between 1 and 100, determine if it is a Harshad number (divisible by the sum of its digits). If it is, return the sum of its digits; otherwise, return -1.

## Approach

The solution computes the sum of the digits by repeatedly extracting the last digit using modulo 10 and dividing by 10 until the number is reduced to zero. A temporary variable `g` holds the working copy of `x` while `out` accumulates the digit sum.

Once the digit sum is calculated, the code checks whether `x` is divisible by this sum using the modulo operator. If `x % out` is non-zero, the number is not a Harshad number and the function returns -1. Otherwise, it returns the computed digit sum.

This is a straightforward simulation approach that directly implements the definition of a Harshad number without any optimization or preprocessing.

## Complexity

- **Time:** O(log x)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-04 05:04 UTC
- Runtime: 2 ms
- Memory: 7.6 MB
- Language: C++
