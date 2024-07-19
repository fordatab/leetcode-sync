# Defanging an IP Address

**Difficulty:** Easy
**Tags:** string, string-manipulation, iteration

## Problem

Given a valid IPv4 address as a string, transform it by replacing each period character with the three-character sequence "[.]". The input is guaranteed to be a properly formatted IPv4 address.

## Approach

The solution iterates through each character of the input string. For each character, if it's a period, the string "[.]" is appended to the result string; otherwise, the character itself is appended unchanged. This straightforward character-by-character transformation builds up the defanged address incrementally using string concatenation.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-19 09:00 UTC
- Runtime: 3 ms
- Memory: 7.5 MB
- Language: C++
