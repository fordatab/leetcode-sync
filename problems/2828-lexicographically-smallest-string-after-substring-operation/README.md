# Lexicographically Smallest String After Substring Operation

**Difficulty:** Medium
**Tags:** string, greedy

## Problem

Given a string of lowercase English letters, you must select exactly one non-empty substring and replace each character with its preceding letter in the alphabet (where 'a' wraps to 'z'). The goal is to find the lexicographically smallest string achievable after performing this required operation once.

## Approach

The solution uses a greedy strategy to minimize the lexicographic order. It first searches for the leftmost character that is not 'a' using `find_first_not_of('a')`. If no such character exists (the entire string is 'a's), we must still perform an operation, so we decrement only the last character from 'a' to 'z'. Otherwise, starting from the first non-'a' character, we decrement consecutive characters until we encounter an 'a' or reach the end of the string. This approach ensures we reduce characters as early as possible in the string (for lexicographic minimality) while avoiding converting any 'a' to 'z' (which would increase lexicographic order), except when forced to operate on an all-'a' string.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-05 10:05 UTC
- Runtime: 5 ms
- Memory: 43.9 MB
- Language: C++
