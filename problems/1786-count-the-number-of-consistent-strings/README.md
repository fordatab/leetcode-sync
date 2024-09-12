# Count the Number of Consistent Strings

**Difficulty:** Easy
**Tags:** hash-table, string, array, bit-manipulation

## Problem

Given a string of distinct allowed characters and an array of words, count how many words contain only characters that appear in the allowed string. Each word can use allowed characters in any combination or frequency, but cannot contain any character not in the allowed set. The allowed string has at most 26 characters, and there can be up to 10,000 words with each word having at most 10 characters.

## Approach

The solution uses a boolean lookup table to track which characters are allowed. First, it creates a 26-element boolean vector (one slot per lowercase letter) and marks each character in the allowed string as true by converting characters to indices via `c-'a'`. Then it iterates through each word in the input array, checking every character against this lookup table. For each word, it maintains a boolean flag that starts as true and gets set to false if any character is not in the allowed set. The flag's final value (converted to int) is added to the running count, effectively incrementing the counter only for words where all characters passed the check.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-12 05:45 UTC
- Runtime: 38 ms
- Memory: 34 MB
- Language: C++
