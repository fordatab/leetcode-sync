# Word Break

**Difficulty:** Medium
**Tags:** dynamic-programming, string, backtracking

## Problem

Given a string and a dictionary of words, determine whether the string can be completely segmented into a sequence of dictionary words, where each word can be reused any number of times. The string has a maximum length of 300 characters, and the dictionary contains up to 1000 unique words, each up to 20 characters long.

## Approach

This solution uses dynamic programming with a boolean array `dp` where `dp[i]` indicates whether the substring starting at index `i` can be segmented using the dictionary words.

The algorithm works backwards from the end of the string. It initializes `dp[n]` (one position past the end) as `true`, representing an empty suffix that trivially requires no segmentation. For each position `x` from `n-1` down to 0, it tries matching each dictionary word at that position.

If a word matches the substring starting at `x` and the remaining substring (starting at `x + word.length`) can be segmented (indicated by `dp[x + word.length()]` being true), then `dp[x]` is set to `true` and the inner loop breaks early. The final answer is `dp[0]`, which tells us whether the entire string can be segmented.

The key insight is that the problem exhibits optimal substructure: if we can segment the string from position `i` onwards, and we find a valid word at position `j < i`, then we can segment from position `j` onwards by combining that word with the solution starting at `i`.

## Complexity

- **Time:** O(n * m * k)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-24 01:11 UTC
- Runtime: 6 ms
- Memory: 10.5 MB
- Language: C++
