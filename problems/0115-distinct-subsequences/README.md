# Distinct Subsequences

**Difficulty:** Hard
**Tags:** dynamic-programming, string, subsequence

## Problem

Given two strings s and t, count how many distinct subsequences of s are equal to t. A subsequence is formed by deleting zero or more characters from s without changing the order of remaining characters. The strings can be up to 1000 characters long, and the result fits in a 32-bit integer.

## Approach

This solution uses dynamic programming with a 2D table where `dp[i][j]` represents the number of distinct subsequences of `s[i:]` that equal `t[j:]`. The table is filled bottom-up, starting from the end of both strings.

The base cases set `dp[i][n] = 1` for all i (an empty target can be formed in exactly one way by any source string) and `dp[m][j] = 0` for j < n (an empty source cannot form a non-empty target).

For each cell, if characters `s[i]` and `t[j]` match, we have two choices: either use this character match (adding `dp[i+1][j+1]`) or skip this character in s (adding `dp[i+1][j]`). If they don't match, we can only skip the current character in s, taking `dp[i+1][j]`.

The final answer is found at `dp[0][0]`, representing the count of subsequences of the entire string s that equal the entire string t. A modulo operation is applied to keep values within bounds.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-28 01:40 UTC
- Runtime: 22 ms
- Memory: 20.1 MB
- Language: C++
