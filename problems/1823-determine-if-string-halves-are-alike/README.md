# Determine if String Halves Are Alike

**Difficulty:** Easy
**Tags:** two-pointers, string, bit-manipulation

## Problem

Given a string of even length, split it into two equal halves and determine if they contain the same number of vowels (both uppercase and lowercase a, e, i, o, u count). Return true if the vowel counts are equal, false otherwise. The string length is between 2 and 1000 and is always even.

## Approach

The solution uses a two-pointer approach with a running counter to track the vowel difference between halves. First, it normalizes all characters to lowercase by setting the 6th bit (OR with 0x20), which converts uppercase letters to lowercase. It initializes two pointers: `l` starting at the last character of the first half and `r` starting at the first character of the second half. As it iterates inward, it increments a counter `v` for each vowel found in the first half and decrements it for each vowel in the second half. After processing all characters, if the counter is zero, the halves have equal vowel counts. This avoids explicitly counting and comparing separate totals.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-14 00:49 UTC
- Runtime: 16 ms
- Memory: 8.1 MB
- Language: C++
