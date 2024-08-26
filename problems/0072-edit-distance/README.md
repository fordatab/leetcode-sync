# Edit Distance

**Difficulty:** Medium
**Tags:** dynamic-programming, string, edit-distance, matrix

## Problem

Given two strings, find the minimum number of single-character edits (insertion, deletion, or replacement) needed to transform the first string into the second. Both strings consist of lowercase English letters and can have lengths from 0 to 500.

## Approach

This solution uses bottom-up dynamic programming with a 2D table. The `dp[i][j]` entry represents the minimum edit distance between the suffix of `word1` starting at index `i` and the suffix of `word2` starting at index `j`.

The base cases initialize the last row and column: converting any suffix to an empty string requires deletions equal to the remaining length. The recurrence processes indices from the end backwards to the start.

For each position `(i, j)`, if the characters match, no edit is needed and we inherit the result from `dp[i+1][j+1]`. If they differ, we take the minimum of three options: insert (look at `dp[i][j+1]`), delete (look at `dp[i+1][j]`), or replace (look at `dp[i+1][j+1]`), adding 1 for the operation cost.

The final answer is found at `dp[0][0]`, representing the edit distance between the full strings starting from index 0.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-26 07:00 UTC
- Runtime: 10 ms
- Memory: 12.9 MB
- Language: C++
