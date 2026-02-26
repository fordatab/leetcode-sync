# Minimum Insertion Steps to Make a String Palindrome

**Difficulty:** Hard
**Tags:** dynamic-programming, string, palindrome

## Problem

Given a string of lowercase English letters with length up to 500, determine the minimum number of character insertions needed at any positions to transform it into a palindrome. The goal is to find the smallest count of insertions that make the string read the same forwards and backwards.

## Approach

The solution uses dynamic programming on substrings to find the minimum insertions needed. It builds a 2D table `dp[l][r]` representing the minimum insertions required to make the substring from index `l` to `r` a palindrome.

The algorithm iterates through all possible substring lengths from 2 to N. For each substring, if the characters at both ends match (`s[l] == s[r]`), no additional insertion is needed beyond what's required for the inner substring, so `dp[l][r] = dp[l+1][r-1]`. If they don't match, we need one insertion plus the minimum of either making the substring without the left character a palindrome or making the substring without the right character a palindrome: `dp[l][r] = 1 + min(dp[l+1][r], dp[l][r-1])`.

Base cases (substrings of length 1) are implicitly handled as they require 0 insertions, which is the default value in the initialized vector. The final answer is found in `dp[0][N-1]`, representing the entire string.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2026-02-26 00:17 UTC
- Runtime: 20 ms
- Memory: 31.3 MB
- Language: C++
