# Lexicographically Smallest Palindrome

**Difficulty:** Easy
**Tags:** two-pointers, string, palindrome, greedy

## Problem

Given a string of lowercase English letters, transform it into a palindrome using the minimum number of character replacements. If multiple palindromes require the same minimum number of operations, return the lexicographically smallest one. The string length can be up to 1000 characters.

## Approach

The solution uses a two-pointer technique starting from the center of the string and moving outward. It initializes both pointers at the middle (adjusting for even-length strings by placing the left pointer one position back). For each pair of mirror positions, if the characters differ, it replaces the lexicographically larger character with the smaller one. This ensures both palindrome property and lexicographic minimality in a single pass. The algorithm processes each mirrored pair exactly once, modifying the string in-place and returning the result after all pairs have been examined.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-15 02:48 UTC
- Runtime: 42 ms
- Memory: 18.7 MB
- Language: C++
