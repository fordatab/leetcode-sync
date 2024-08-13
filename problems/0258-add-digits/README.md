# Add Digits

**Difficulty:** Easy
**Tags:** math, number-theory, digital-root

## Problem

Given a non-negative integer up to 2^31 - 1, repeatedly sum its digits until only a single digit remains, then return that digit. For example, 38 becomes 11 (3+8), which becomes 2 (1+1).

## Approach

This solution uses the mathematical property known as digital root, which relates to modulo 9 arithmetic. Instead of iterating to sum digits repeatedly, it directly computes the result using the pattern that the digital root of a positive number equals 9 if the number is divisible by 9, otherwise it equals the remainder when divided by 9. The code handles three cases: zero returns 0, multiples of 9 (excluding 0) return 9, and all other numbers return their remainder modulo 9. This exploits the fact that a number and the sum of its digits are congruent modulo 9, and repeatedly summing digits converges to a value between 1 and 9.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-13 04:22 UTC
- Runtime: 0 ms
- Memory: 8.4 MB
- Language: C++
