# Keyboard Row

**Difficulty:** Easy
**Tags:** string, binary-search, array, filtering

## Problem

Given an array of words, identify which words can be typed using only letters from a single row of a standard QWERTY keyboard. The three rows are defined as 'qwertyuiop', 'asdfghjkl', and 'zxcvbnm'. The comparison is case-insensitive, and words must have all their letters on the same row to qualify.

## Approach

The solution predefines three sorted character arrays representing the keyboard rows (sorted alphabetically rather than by keyboard layout). For each word, it determines which row the first character belongs to by checking all three rows with binary search, then verifies that every subsequent character in the word also belongs to that same row using additional binary searches.

The binary search implementation follows the standard pattern: it maintains left and right pointers, computes the midpoint, and narrows the search space based on comparisons until the character is found or the search space is exhausted. All characters are converted to lowercase before searching to handle case-insensitivity.

Words that pass the validation (all characters from one row) are collected in an ArrayList, which is then converted to a String array for the return value. The solution defaults to checking against the third row if the first character isn't found in rows one or two.

## Complexity

- **Time:** O(n * m * log k)
- **Space:** O(n)

## Stats

- Submitted: 2022-03-06 17:47 UTC
- Runtime: 1 ms
- Memory: 41.6 MB
- Language: Java
