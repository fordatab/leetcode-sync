# Substring Matching Pattern

**Difficulty:** Easy
**Tags:** string, pattern-matching, two-pointers

## Problem

Given a string s and a pattern p containing exactly one asterisk wildcard, determine if p can match any substring of s where the asterisk can be replaced by zero or more characters. The pattern splits into a prefix and suffix around the asterisk, and both parts must appear in s in the correct order with possible overlap or gap.

## Approach

The solution splits the pattern at the asterisk into a prefix (before '*') and suffix (after '*'). It then searches for the first occurrence of the prefix in s using `find()` and the last occurrence of the suffix using `rfind()`. The key insight is that if both parts exist in s and the prefix starts at or before where the suffix could begin (accounting for the prefix length), then some substring of s matches the pattern. The condition `i + b.size() <= j` ensures the prefix ends at or before the suffix starts, allowing the asterisk to represent zero or more characters between them.

## Complexity

- **Time:** O(n * m)
- **Space:** O(m)

## Stats

- Submitted: 2026-01-20 10:27 UTC
- Runtime: 1 ms
- Memory: 9.1 MB
- Language: C++
