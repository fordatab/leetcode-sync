# Word Pattern

**Difficulty:** Easy
**Tags:** hash-table, string, two-pointers, bijection

## Problem

Given a pattern string of lowercase letters and a sentence of space-separated words, determine if the sentence follows the same pattern as the pattern string. This requires establishing a one-to-one correspondence (bijection) where each unique character maps to exactly one unique word and vice versa, with the pattern length matching the word count.

## Approach

The solution uses two hash maps to maintain bidirectional mappings between pattern characters and words. It iterates through the pattern string while simultaneously extracting words from the input sentence using a stringstream. For each pattern character, it extracts the corresponding word and checks if either mapping already exists but conflicts with the current pairing. If a character is already mapped to a different word, or a word is already mapped to a different character, the function returns false. After processing all pattern characters, it verifies that no extra words remain in the sentence. Both mappings are updated at each step to ensure the bijection property is maintained throughout.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-28 06:38 UTC
- Runtime: 4 ms
- Memory: 8 MB
- Language: C++
