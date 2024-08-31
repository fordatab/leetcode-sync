# Isomorphic Strings

**Difficulty:** Easy
**Tags:** hash-table, string, array

## Problem

Given two strings of equal length, determine whether one can be transformed into the other by consistently replacing each character with another. Each character in the first string must map to exactly one character in the second string, and this mapping must be bijective (one-to-one). The strings consist of valid ASCII characters and can be up to 50,000 characters long.

## Approach

The solution uses two integer arrays of size 128 (covering all ASCII characters) to track the last position where each character was seen in both strings. It iterates through both strings simultaneously, checking at each position whether the character from `s` and the character from `t` were last seen at the same relative position. If the stored positions differ, it means the mapping is inconsistent (either a character from `s` maps to multiple characters in `t`, or vice versa), so the function returns false. After checking, both arrays are updated with the current position plus one (to distinguish from the initial zero value). If all positions pass the consistency check, the strings are isomorphic.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-31 04:27 UTC
- Runtime: 6 ms
- Memory: 8.4 MB
- Language: C++
