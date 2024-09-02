# String to Integer (atoi)

**Difficulty:** Medium
**Tags:** string, parsing, state-machine, overflow-handling

## Problem

The task is to parse a string into a 32-bit signed integer following specific rules: skip leading whitespace, detect an optional sign ('+' or '-'), read consecutive digit characters until a non-digit is found, and clamp the result to the range [-2³¹, 2³¹-1]. The string may contain up to 200 characters including letters, digits, spaces, and punctuation.

## Approach

The solution uses a single-pass state machine approach with an index pointer. First, it advances through any leading spaces. Next, it checks for a sign character ('-' or '+') and records whether the number is negative. Then it enters a digit-reading loop that processes characters '0'-'9', building the result by multiplying the accumulator by 10 and adding each digit's numeric value.

The key insight is overflow detection before performing the multiplication: the code checks if the current result exceeds INT_MAX/10, or if it equals INT_MAX/10 and the next digit would push it over the boundary (digit > 7 for positive numbers). When overflow is detected, it immediately returns the appropriate boundary value (INT_MIN or INT_MAX) based on the sign.

The solution accumulates the absolute value in a positive integer, then applies the sign at the end by negating if necessary. This allows a single overflow check condition to work for both positive and negative numbers.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-02 07:23 UTC
- Runtime: 3 ms
- Memory: 9 MB
- Language: C++
