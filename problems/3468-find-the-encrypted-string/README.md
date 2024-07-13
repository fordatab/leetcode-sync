# Find the Encrypted String

**Difficulty:** Easy
**Tags:** string, array, modular-arithmetic

## Problem

Given a string and an integer k, create an encrypted version where each character at position i is replaced by the character k positions ahead in a circular fashion. The string wraps around, so counting past the end continues from the beginning. The output should be a transformed string of the same length.

## Approach

The solution iterates through each position in the input string and builds the output character-by-character. For each position `x`, it calculates the source position as `(x + k) % s.size()`, which handles the cyclic wrapping automatically through the modulo operation. A fixed-size character array is allocated to hold the result, with a null terminator added at the end before converting to a C++ string. The modulo ensures that even when k is larger than the string length, the correct wraparound position is computed.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-13 00:47 UTC
- Runtime: 5 ms
- Memory: 8 MB
- Language: C++
