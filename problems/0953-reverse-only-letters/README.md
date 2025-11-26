# Reverse Only Letters

**Difficulty:** Easy
**Tags:** two-pointers, string, string-manipulation

## Problem

Given a string containing letters and non-letter characters, reverse only the letters while keeping all non-letter characters in their original positions. The string length is at most 100 and consists of ASCII characters in the range [33, 122], excluding quotes and backslashes.

## Approach

The solution uses a two-pointer technique with one pointer starting from the left (l) and another from the right (r). It builds the output string by processing characters from right to left. When the right pointer finds a letter, it checks if the left pointer is also at a letter position; if so, it places the right character at the left position and advances both pointers. If the left pointer is at a non-letter, it copies that non-letter to the output and only advances the left pointer. When the right pointer encounters a non-letter, it copies that character directly to its original position in the output and moves left. This continues until all characters are processed, effectively reversing only the alphabetic characters while preserving non-letter positions.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-11-26 01:30 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
