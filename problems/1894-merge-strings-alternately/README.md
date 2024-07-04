# Merge Strings Alternately

**Difficulty:** Easy
**Tags:** two-pointers, string, simulation

## Problem

Given two strings, construct a new string by taking characters from each input string in alternating fashion, beginning with the first string. When one string runs out of characters before the other, append all remaining characters from the longer string to the result. Both input strings contain only lowercase English letters and have lengths between 1 and 100.

## Approach

The solution uses a two-phase approach with a single index variable. In the first phase, it iterates while the index is valid for both strings, appending one character from each string alternately to the output string. The loop continues until reaching the end of the shorter string. In the second phase, it uses `substr` to append any remaining characters from whichever string still has unprocessed characters. Since `substr` handles out-of-bounds gracefully (returning an empty string when the start index equals or exceeds the string length), both `substr` calls are made unconditionally, though only one will actually contribute characters.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-04 18:49 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
