# Reverse Prefix of Word

**Difficulty:** Easy
**Tags:** string, two-pointers, string-manipulation

## Problem

Given a string and a target character, find the first occurrence of that character and reverse the substring from the beginning up to and including that character. If the character doesn't exist in the string, return the original string unchanged. The input string has length between 1 and 250 and consists only of lowercase English letters.

## Approach

The solution uses the built-in `find` method to locate the first occurrence of the target character in the string. The `find` method returns the index of the character if found, or `string::npos` if not found.

If the character is found (index is not `string::npos`), the code uses the `reverse` function from the standard library to reverse the range from the beginning of the string (`word.begin()`) to the position just after the found character (`word.begin() + idx + 1`). The `+ 1` ensures the target character itself is included in the reversal.

If the character is not found, no reversal is performed and the original string is returned. This approach leverages efficient C++ standard library functions for both searching and reversing.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-20 05:39 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
