# Split Strings by Separator

**Difficulty:** Easy
**Tags:** string, array, string-manipulation, iteration

## Problem

Given an array of strings and a separator character, split each string at every occurrence of the separator and return all non-empty resulting substrings in their original order. The separator itself should not appear in the output, and consecutive separators or separators at string boundaries produce empty strings that must be excluded.

## Approach

The solution iterates through each word in the input array. For each word, it scans character by character, building up a temporary string. When the separator is encountered and the temporary string is non-empty, the temporary string is added to the result and reset. Non-separator characters are accumulated into the temporary string. After processing all characters in a word, if there's remaining content in the temporary string (meaning the word didn't end with a separator), it's also added to the result. This manual parsing approach avoids empty strings by only adding the temporary buffer when it contains actual characters.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n * m)

## Stats

- Submitted: 2024-09-14 03:49 UTC
- Runtime: 28 ms
- Memory: 44 MB
- Language: C++
