# Reverse Words in a String III

**Difficulty:** Easy
**Tags:** string, two-pointers, string-manipulation

## Problem

Given a string containing words separated by single spaces, reverse the character order within each individual word while maintaining the original word positions and spacing. The input string has no leading or trailing spaces and contains at least one word, with a maximum length of 50,000 characters.

## Approach

The solution iterates through the input string to find word boundaries using the `find()` method to locate space characters. For each word found:

- Extract the substring from the current position to the space using `substr()`
- Reverse the extracted word in-place using the STL `reverse()` function
- Append the reversed word and a space to the output string
- Move the position marker past the space

After the loop completes (when no more spaces are found), the final word from the current position to the end of the string is extracted, reversed, and appended without a trailing space. The algorithm processes words sequentially in a single pass through the string.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 00:10 UTC
- Runtime: 18 ms
- Memory: 15.3 MB
- Language: C++
