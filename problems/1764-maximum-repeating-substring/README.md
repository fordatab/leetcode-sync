# Maximum Repeating Substring

**Difficulty:** Easy
**Tags:** dynamic-programming, string, substring-matching

## Problem

Given two strings, sequence and word, find the maximum number of consecutive repetitions k such that word repeated k times appears as a substring within sequence. The length of both strings is at most 100, and both contain only lowercase English letters. Return 0 if word doesn't appear in sequence at all.

## Approach

The solution uses dynamic programming with a 1D array `dp` where `dp[i]` represents the maximum number of consecutive repetitions of `word` ending at position `i` in the sequence.

It iterates through the sequence starting from index `m` (the length of `word`). At each position `i`, it checks if the substring of length `m` ending at position `i` matches `word` using `substr(i - m, m)`.

If a match is found, `dp[i]` is set to `dp[i - m] + 1`, effectively counting how many times `word` has repeated consecutively up to this point by building on the count from `m` positions earlier.

Finally, it returns the maximum value in the `dp` array, which represents the highest k-repeating value found anywhere in the sequence.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-05 04:58 UTC
- Runtime: 0 ms
- Memory: 8.4 MB
- Language: C++
