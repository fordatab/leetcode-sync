# Longest Common Prefix

**Difficulty:** Easy
**Tags:** string, array, prefix

## Problem

Given an array of strings, find the longest prefix that appears at the start of every string in the array. The array contains between 1 and 200 strings, each up to 200 characters long and consisting only of lowercase English letters. If no common prefix exists, return an empty string.

## Approach

The solution uses a character-by-character comparison approach. First, it finds the length of the shortest string in the array, since the common prefix cannot be longer than the shortest string. Then it iterates through each character position from 0 to this minimum length. At each position, it takes the character from the first string and compares it against the character at the same position in all other strings. If all strings have the same character at that position, it appends the character to the result. As soon as a mismatch is found at any position, the iteration stops and the accumulated prefix is returned.

## Complexity

- **Time:** O(n * m)
- **Space:** O(m)

## Stats

- Submitted: 2022-06-08 12:09 UTC
- Runtime: 1 ms
- Memory: 40 MB
- Language: Java
