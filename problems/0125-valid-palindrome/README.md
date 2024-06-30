# Valid Palindrome

**Difficulty:** Easy
**Tags:** two-pointers, string, palindrome

## Problem

Given a string containing various ASCII characters, determine whether it forms a palindrome when considering only alphanumeric characters (letters and numbers) in a case-insensitive manner. All other characters like spaces, punctuation, and symbols should be ignored. The string can be up to 200,000 characters long.

## Approach

The solution uses a two-pointer technique to check for palindrome properties without preprocessing the string. Two pointers start at opposite ends of the string and move toward each other. At each step, the algorithm skips over non-alphanumeric characters by advancing the left pointer rightward or the right pointer leftward until both point to valid alphanumeric characters. Once both pointers reference alphanumeric characters, it compares them in a case-insensitive manner using `tolower()`. If the characters match, both pointers move inward; if they don't match, the function immediately returns false. The process continues until the pointers meet or cross, at which point the string is confirmed to be a palindrome. Special boundary checks handle cases where all characters are non-alphanumeric.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-30 06:42 UTC
- Runtime: 9 ms
- Memory: 8.6 MB
- Language: C++
