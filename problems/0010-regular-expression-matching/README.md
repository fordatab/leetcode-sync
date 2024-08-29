# Regular Expression Matching

**Difficulty:** Hard
**Tags:** dynamic-programming, string, recursion, pattern-matching

## Problem

The task is to determine if a pattern containing lowercase letters, '.', and '*' matches an entire input string. The '.' wildcard matches any single character, while '*' matches zero or more occurrences of the character immediately before it. Both the string and pattern are at most 20 characters long, and the pattern guarantees that every '*' has a valid preceding character.

## Approach

This solution uses bottom-up dynamic programming with a 2D table where `dp[i][j]` indicates whether the substring `s[i:]` matches the pattern `p[j:]`. The table is initialized with `dp[m][n] = true` (empty string matches empty pattern). 

The algorithm iterates backwards through both strings. For each position, it first checks if the current characters match (either they're equal or the pattern has a '.'). If the next pattern character is '*', there are two cases: skip the starred pattern (use zero occurrences via `dp[i][j+2]`), or if the current characters match, consume one character from the string and stay at the same pattern position (via `dp[i+1][j]`). If there's no '*', a match requires the current characters to match and the remainders to match (`dp[i+1][j+1]`).

The final answer is `dp[0][0]`, representing whether the full string matches the full pattern from the beginning.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-29 22:32 UTC
- Runtime: 7 ms
- Memory: 9.7 MB
- Language: C++
