# Longest Substring Without Repeating Characters

**Difficulty:** Medium
**Tags:** sliding-window, hash-set, two-pointers, string

## Problem

Given a string containing various characters, determine the length of the longest contiguous substring where no character appears more than once. The string can be up to 50,000 characters long and may include letters, digits, symbols, and spaces.

## Approach

The solution uses a sliding window technique with two pointers (`l` and `r`) and an unordered set to track characters in the current window.

The right pointer `r` expands the window by moving through the string. When a character at `r` is not in the set, it's added and the maximum length is updated based on the set size. When a duplicate is encountered (character at `r` is already in the set), the left pointer `l` contracts the window by removing characters until the duplicate at position `l` is found and removed, then `l` advances past it.

The key insight is maintaining a valid window of unique characters: expand when possible, contract when duplicates appear. The maximum set size seen during this process is the answer.

The algorithm processes each character with the right pointer moving forward once per iteration, while the left pointer only moves when duplicates are detected to restore the uniqueness invariant.

## Complexity

- **Time:** O(n)
- **Space:** O(min(n, m))

## Stats

- Submitted: 2024-07-10 07:19 UTC
- Runtime: 18 ms
- Memory: 11.9 MB
- Language: C++
