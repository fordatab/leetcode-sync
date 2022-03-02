# Find Common Characters

**Difficulty:** Easy
**Tags:** array, hash-table, string, counting

## Problem

Given an array of strings containing only lowercase English letters, identify all characters that appear in every string, preserving duplicate occurrences. For example, if 'l' appears twice in all strings, it should appear twice in the output. The array can contain 1 to 100 strings, each 1 to 100 characters long.

## Approach

The solution uses a frequency counting approach with a 2D array. It allocates a 100×26 matrix where each row corresponds to a word and each column represents a letter (a-z). For each word, it counts the frequency of each character by converting characters to indices (subtracting 97, the ASCII value of 'a'). After building the frequency table, it iterates through all 26 possible letters and finds the minimum occurrence count across all words. For each letter, it adds that many copies to the result list by converting the index back to a character (adding 97). This ensures only characters present in all strings are included, with their count limited to the minimum frequency across all words.

## Complexity

- **Time:** O(n * m + 26 * n)
- **Space:** O(n)

## Stats

- Submitted: 2022-03-02 04:03 UTC
- Runtime: 4 ms
- Memory: 45 MB
- Language: Java
