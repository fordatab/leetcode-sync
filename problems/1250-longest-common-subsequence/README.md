# Longest Common Subsequence

**Difficulty:** Medium
**Tags:** dynamic-programming, string, bottom-up-dp, 2d-array

## Problem

Given two strings, find the length of their longest common subsequence—a sequence of characters that appears in both strings in the same relative order, though not necessarily consecutively. The strings consist only of lowercase English letters and each has a length between 1 and 1000. If no common subsequence exists, return 0.

## Approach

This solution uses bottom-up dynamic programming with a 2D table. The DP table has dimensions (m+1) × (n+1) where m and n are the lengths of text1 and text2 respectively.

The algorithm fills the table in reverse order, starting from the bottom-right corner (position [m-1][n-1]) and moving toward the top-left (position [0][0]). For each cell [i][j], if the characters text1[i] and text2[j] match, the subsequence length at this position is 1 plus the length from the diagonal cell [i+1][j+1]. If the characters don't match, the cell takes the maximum of the subsequence lengths from either skipping the current character in text1 (cell [i+1][j]) or skipping it in text2 (cell [i][j+1]).

The extra row and column (indices m and n) are initialized to 0 and serve as base cases, representing empty suffixes. The final answer is found in dp[0][0], which represents the LCS length considering both full strings.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-25 06:45 UTC
- Runtime: 31 ms
- Memory: 26 MB
- Language: C++
