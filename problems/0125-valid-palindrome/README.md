# Valid Palindrome

**Difficulty:** Easy
**Tags:** two-pointers, string, palindrome

## Problem

Given a string containing uppercase letters, lowercase letters, numbers, and other ASCII characters, determine whether the sequence of alphanumeric characters (letters and digits) reads the same forwards and backwards when case is ignored. The input string can be up to 200,000 characters long.

## Approach

The solution uses a two-pointer technique, starting with one pointer at the beginning (`l`) and another at the end (`r`) of the string. It iterates inward, skipping any non-alphanumeric characters by advancing the appropriate pointer. When both pointers land on alphanumeric characters, it compares them in lowercase form. If any mismatch is found, the function immediately returns false. If the pointers meet or cross without finding a mismatch, the string is confirmed as a palindrome and the function returns true. The use of `tolower()` ensures case-insensitive comparison, and `isalnum()` filters out non-alphanumeric characters.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-10-04 09:44 UTC
- Runtime: 2 ms
- Memory: 8.5 MB
- Language: C
