# Valid Anagram

**Difficulty:** Easy
**Tags:** hash-table, string, frequency-counting, array

## Problem

Given two strings containing only lowercase English letters (each up to 50,000 characters), determine whether one string is an anagram of the other — that is, whether they contain exactly the same characters with the same frequencies. The strings must have identical character counts for all 26 letters to be anagrams.

## Approach

This solution uses frequency counting with fixed-size arrays. It creates two integer arrays of size 26, one for each string, where each index represents a lowercase letter ('a' at index 0 through 'z' at index 25). The code iterates through the first string and increments the corresponding counter in `char_s` by subtracting 97 (ASCII value of 'a') from each character to get its array index. It does the same for the second string with `char_t`. Finally, it compares all 26 positions in both arrays; if any frequency differs, the strings are not anagrams and the function returns false. If all frequencies match, it returns true.

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-27 02:52 UTC
- Runtime: 7 ms
- Memory: 8.5 MB
- Language: C++
