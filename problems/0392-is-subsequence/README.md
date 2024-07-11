# Is Subsequence

**Difficulty:** Easy
**Tags:** two-pointers, string, greedy

## Problem

Given two strings s and t, determine whether s is a subsequence of t. A subsequence is formed by deleting zero or more characters from the original string without changing the order of remaining characters. The strings contain only lowercase English letters, with s having at most 100 characters and t having at most 10,000 characters.

## Approach

The solution uses a two-pointer greedy approach. It maintains an index `i` tracking the current position in string `s` that needs to be matched. The algorithm iterates through each character in string `t` using a range-based for loop. When a character in `t` matches the current character in `s` (at position `i`), the index is incremented. If all characters of `s` are matched (when `i` reaches `s.size()`), the function returns true immediately. If the loop completes without matching all characters of `s`, the function returns false. The solution includes an optimization for the empty string case, returning true immediately since an empty string is a subsequence of any string.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 04:09 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
