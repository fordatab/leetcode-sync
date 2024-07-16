# Find the Encrypted String

**Difficulty:** Easy
**Tags:** string, array, modular-arithmetic

## Problem

Given a string and an integer k, create an encrypted version by replacing each character at position i with the character at position (i+k) % length, wrapping around cyclically. The string consists only of lowercase letters and has length between 1 and 100, while k can be up to 10,000.

## Approach

The solution uses modular arithmetic to handle the cyclic rotation. It creates a temporary buffer `out` of the same size as the input string. For each position `x` in the original string, it calculates the source position as `(x+k) % size`, which naturally wraps around when k is larger than the string length. After building the entire encrypted string in the temporary buffer and null-terminating it, the result is copied back into the original string buffer (which is safe since the input is mutable in C), and that pointer is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-16 06:03 UTC
- Runtime: 2 ms
- Memory: 8 MB
- Language: C
