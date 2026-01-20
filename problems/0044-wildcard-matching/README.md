# Wildcard Matching

**Difficulty:** Hard
**Tags:** dynamic-programming, string-matching, wildcard, two-pointer

## Problem

Determine whether a text string can be matched entirely by a pattern containing lowercase letters, '?' (which matches any single character), and '*' (which matches zero or more characters). Both the string and pattern can be up to 2000 characters long, and the match must cover the complete string with no leftover characters.

## Approach

This solution uses a 2D dynamic programming table where `dp[x][y]` indicates whether the first `x` characters of the pattern match the first `y` characters of the string.

For each pattern character, the code handles three cases:
- **Literal character**: Match only if it equals the corresponding string character and the previous state was valid.
- **'?' wildcard**: Acts as a single-character match, propagating the diagonal predecessor state.
- **'*' wildcard**: First finds the earliest position where a match exists (the first true value in the previous row). From that position onward, it marks all subsequent positions as true, representing that '*' can consume zero or more characters.

The algorithm fills the table row by row (pattern position by pattern position), and the final answer is whether `dp[n][m]` is true, indicating the entire pattern matches the entire string.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n * m)

## Stats

- Submitted: 2026-01-20 10:18 UTC
- Runtime: 27 ms
- Memory: 14 MB
- Language: C++
