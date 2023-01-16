# Palindrome Number

**Difficulty:** Easy
**Tags:** string, two-pointers, math

## Problem

Determine whether an integer reads the same forwards and backwards. Negative numbers are never palindromes because of the minus sign. The input range spans the full signed 32-bit integer domain.

## Approach

The solution converts the integer to a string using `std::to_string`, then iterates through the first half of the string comparing each character with its mirror position from the end. If any pair of characters doesn't match, it returns false immediately. If all comparisons succeed, the function returns true. This approach handles negative numbers naturally since the string representation includes the minus sign, which won't match its mirror position.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2023-01-16 08:37 UTC
- Runtime: 16 ms
- Memory: 6 MB
- Language: C++
