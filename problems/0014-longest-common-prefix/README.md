# Longest Common Prefix

**Difficulty:** Easy
**Tags:** string, array, vertical-scanning

## Problem

Given an array of strings, find the longest prefix that is common to all strings in the array. If no common prefix exists among all strings, return an empty string. The input contains between 1 and 200 strings, each up to 200 characters long and consisting only of lowercase English letters.

## Approach

The solution uses a character-by-character vertical scanning approach. It iterates through each position in the first string and checks if the character at that position matches across all other strings in the array.

For each character position `i` in the first string, it extracts that character and compares it with the character at the same position in every other string. If a mismatch is found (or if any string is too short and doesn't have a character at position `i`), it immediately returns the substring of the first string from index 0 to the current length `l`.

A counter `l` tracks how many characters have been successfully matched across all strings. After successfully verifying a character position across all strings, `l` is incremented. If the loop completes without finding any mismatch, the entire first string (up to length `l`) is the common prefix.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-15 06:52 UTC
- Runtime: 0 ms
- Memory: 11.8 MB
- Language: C++
