# Repeated Substring Pattern

**Difficulty:** Easy
**Tags:** string, string-matching, pattern-recognition

## Problem

Given a string of up to 10,000 lowercase English letters, determine whether it can be formed by repeating a substring multiple times. For instance, "abab" can be formed by repeating "ab" twice, while "aba" cannot be formed by repeating any substring.

## Approach

The solution uses a clever string manipulation trick. It concatenates the input string with itself to create a doubled string, then extracts a substring that excludes the first and last characters of this doubled version. If the original string appears within this extracted substring, it means the original string has a repeating pattern.

The key insight is that if a string `s` is made of repeating patterns, then removing the first and last character from `s+s` will still contain `s` somewhere in the middle. For example, with `s = "abab"`, we get `doubled = "abababab"`, and `sub = "bababa"`. Since "abab" appears in "bababa" (at position 1), the pattern repeats.

This works because if `s` consists of `k` repetitions of some pattern `p`, then `s+s` contains `2k` repetitions. Removing one character from each end still leaves at least `k` full repetitions in the middle (as long as `k > 1`), ensuring `s` can be found. If no pattern exists, the original string won't appear in the trimmed doubled string.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 07:26 UTC
- Runtime: 17 ms
- Memory: 14.2 MB
- Language: C++
