# Valid Word Abbreviation

**Difficulty:** Easy
**Tags:** two-pointers, string, simulation

## Problem

Given a word and an abbreviation string, determine if the abbreviation is valid for that word. An abbreviation replaces non-adjacent substrings with their numeric lengths, where numbers cannot have leading zeros and cannot represent empty substrings. The task is to verify that the abbreviation correctly corresponds to the original word.

## Approach

The solution uses a two-pointer approach to simultaneously traverse both the word and abbreviation strings. One pointer (`a`) tracks the position in the original word, while another (`x`) tracks the position in the abbreviation.

When encountering a digit in the abbreviation, the code first checks for leading zeros (which are invalid). It then accumulates consecutive digits to form a complete number, advances the word pointer by that number of positions, and validates that we haven't skipped past the word's end.

When encountering a letter in the abbreviation, the code verifies that the corresponding character in the word matches and that we haven't exhausted the word. Both pointers advance by one position.

Finally, the solution confirms that both strings have been fully consumed by checking if the word pointer equals the word's length.

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2025-11-30 03:39 UTC
- Runtime: 0 ms
- Memory: 8 MB
- Language: C++
