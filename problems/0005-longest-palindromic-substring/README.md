# Longest Palindromic Substring

**Difficulty:** Medium
**Tags:** string, expand-around-center, two-pointers, palindrome

## Problem

Given a string of up to 1000 characters containing only digits and English letters, find and return the longest contiguous substring that reads the same forwards and backwards. If multiple palindromes of the same maximum length exist, any one of them is acceptable.

## Approach

This solution uses the "expand around centers" technique. For each position in the string, it treats that position as a potential center of a palindrome and expands outward in both directions while the characters match.

The algorithm considers two cases at each index: odd-length palindromes (single character center) and even-length palindromes (two character center). For odd-length, both left and right pointers start at index i. For even-length, left starts at i and right starts at i+1.

For each center, the solution expands by decrementing the left pointer and incrementing the right pointer while the characters at those positions are equal and the pointers remain within bounds. Whenever a longer palindrome is found, it updates the result string and tracks the new maximum length.

By checking all possible centers (n positions for odd-length, n-1 positions for even-length), the algorithm ensures it finds the longest palindromic substring in the input string.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-27 05:24 UTC
- Runtime: 21 ms
- Memory: 22.2 MB
- Language: C++
