# Reverse Words in a String

**Difficulty:** Medium
**Tags:** string, two-pointer, string-manipulation

## Problem

Given a string containing words separated by spaces, return a new string with the words in reverse order, joined by single spaces. The input may have leading/trailing spaces or multiple consecutive spaces between words, but the output must normalize all spacing to single spaces between words with no leading or trailing spaces. The string length can be up to 10,000 characters and contains letters, digits, and spaces.

## Approach

The solution traverses the input string character by character, building words as it encounters alphanumeric characters. When a non-alphanumeric character (space) is encountered after building a word, that word is prepended to the output string along with a trailing space, effectively reversing the word order. A boolean flag tracks whether we're currently inside a word to avoid processing consecutive spaces. After the loop, if the string ended with an alphanumeric character, the final accumulated word is prepended to the output. Finally, the last character (an extra trailing space) is removed using substring before returning.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-13 07:16 UTC
- Runtime: 7 ms
- Memory: 23.6 MB
- Language: C++
