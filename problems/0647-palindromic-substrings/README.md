# Palindromic Substrings

**Difficulty:** Medium
**Tags:** string, two-pointers, expand-around-center, palindrome

## Problem

Given a string of up to 1000 lowercase English letters, count how many contiguous substrings are palindromes (read the same forwards and backwards). Each single character counts as a palindrome, and overlapping palindromes are counted separately.

## Approach

The solution uses the "expand around center" technique. For each possible center position in the string, it expands outward to find all palindromes centered there. The code iterates through each index and considers two cases: odd-length palindromes (single character center at position i) and even-length palindromes (center between positions i and i+1). The helper function `countPali` takes left and right pointers, expands them symmetrically while characters match, and counts each valid palindrome discovered during expansion. The total count across all centers gives the final answer.

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 04:11 UTC
- Runtime: 9 ms
- Memory: 21.7 MB
- Language: C++
