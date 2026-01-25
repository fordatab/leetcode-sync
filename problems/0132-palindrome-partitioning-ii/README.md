# Palindrome Partitioning II

**Difficulty:** Hard
**Tags:** dynamic-programming, string, palindrome

## Problem

Given a string of lowercase English letters (length 1-2000), partition it into substrings where each substring is a palindrome. The goal is to determine the minimum number of cuts needed to achieve such a partitioning. For example, "aab" can be split into ["aa", "b"] with 1 cut, while a single-character string requires 0 cuts.

## Approach

The solution uses dynamic programming with two key components: a 2D boolean table to track which substrings are palindromes, and a 1D array to store the minimum cuts needed up to each position.

For each ending position `end` from 0 to n-1, the algorithm considers all possible starting positions `start` from 0 to `end`. It checks if `s[start:end]` forms a palindrome by verifying: (1) the characters at both ends match, and (2) either the substring is very short (length ≤ 3) or the inner substring is already known to be a palindrome.

When a palindrome is found, the algorithm updates the minimum cuts: if the palindrome starts at index 0, no cuts are needed; otherwise, it takes the minimum of the current value and `dp[start-1] + 1` (cuts needed before this palindrome plus one cut to separate it).

The `dp[end]` value represents the minimum cuts needed to partition `s[0:end]` into palindromes. The final answer is stored in `dp[n-1]`.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n^2)

## Stats

- Submitted: 2026-01-25 09:53 UTC
- Runtime: 27 ms
- Memory: 12.1 MB
- Language: C++
