# Count Prefix and Suffix Pairs I

**Difficulty:** Easy
**Tags:** string, two-pointers, brute-force, nested-loops

## Problem

Given an array of strings, count how many ordered pairs (i, j) with i < j exist where the string at index i is simultaneously both a prefix and a suffix of the string at index j. The array can contain up to 50 strings, each up to 10 characters long, consisting only of lowercase letters.

## Approach

The solution uses a nested loop to examine all pairs (i, j) where i < j. For each pair, it first checks if `words[i]` is no longer than `words[j]` (a necessary condition for it to be both prefix and suffix). Then it verifies two conditions:

1. It extracts a prefix from `words[j]` of length equal to `words[i]` using `substr(0, words[x].size())` and compares it to `words[i]`.
2. It extracts a suffix from `words[j]` of the same length using `substr(suffix.size() - words[x].size())` and compares it to `words[i]`.

A boolean flag `t` tracks whether both conditions hold. If they do, the counter is incremented. This brute-force approach checks every valid pair exactly once.

## Complexity

- **Time:** O(n^2 * m)
- **Space:** O(m)

## Stats

- Submitted: 2025-08-29 08:27 UTC
- Runtime: 0 ms
- Memory: 23.4 MB
- Language: C++
