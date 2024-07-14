# Permutation Difference between Two Strings

**Difficulty:** Easy
**Tags:** array, hash-table, string

## Problem

Given two strings where one is a permutation of the other and each character appears at most once, compute the sum of absolute differences between the positions of each character in the two strings. For example, if character 'a' appears at index 0 in the first string and index 3 in the second, it contributes |0-3| = 3 to the total. The strings have length at most 26 and contain only lowercase English letters.

## Approach

The solution uses a lookup table to store character positions from the first string. First, it creates a vector of size 26 (one slot per lowercase letter) and populates it by iterating through string `s`, storing each character's index at position `s[x]-'a'` in the vector. This creates a mapping from each character to its position in `s`.

Then it iterates through string `t`, and for each character at position `x`, it looks up that character's position in `s` using the precomputed vector `b[t[x]-'a']`. It calculates the absolute difference between the current position `x` in `t` and the stored position in `s`, accumulating these differences in variable `a`.

The key insight is that by preprocessing the positions from the first string into an array indexed by character value, we can perform constant-time lookups while iterating through the second string, avoiding nested loops.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:44 UTC
- Runtime: 7 ms
- Memory: 9.3 MB
- Language: C++
