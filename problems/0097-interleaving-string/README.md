# Interleaving String

**Difficulty:** Medium
**Tags:** dynamic-programming, string, two-pointers

## Problem

Given three strings s1, s2, and s3, determine whether s3 can be formed by interleaving s1 and s2 while preserving the relative order of characters from each source string. The combined length of s1 and s2 must equal the length of s3, and each string can have up to 100-200 characters.

## Approach

The solution uses bottom-up dynamic programming with a 2D table where `dp[i][j]` represents whether the substring `s3[i+j:]` can be formed by interleaving `s1[i:]` and `s2[j:]`. The table is initialized with `dp[m][n] = true` (empty strings interleave to form an empty string). The algorithm iterates backwards from the end of both strings to the beginning. At each position (x, y), it checks two possibilities: if the current character in s1 matches the corresponding position in s3 and the remaining substring is valid (via `dp[x+1][y]`), or if the current character in s2 matches and its continuation is valid (via `dp[x][y+1]`). Either match sets `dp[x][y]` to true. The final answer is found at `dp[0][0]`, indicating whether the complete strings can be interleaved.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-27 06:21 UTC
- Runtime: 3 ms
- Memory: 8.5 MB
- Language: C++
