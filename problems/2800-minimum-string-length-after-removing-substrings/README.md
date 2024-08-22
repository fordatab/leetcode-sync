# Minimum String Length After Removing Substrings

**Difficulty:** Easy
**Tags:** stack, string, simulation, greedy

## Problem

Given a string of uppercase English letters, repeatedly remove any occurrence of the substrings "AB" or "CD" until no more such substrings exist. Return the length of the resulting string. The string length is at most 100, and after removing a substring, the remaining parts concatenate, potentially creating new removable substrings.

## Approach

The solution uses a stack-based approach implemented with a string. It iterates through each character of the input string. For each character, it checks if the string (acting as a stack) is non-empty and if the current character combined with the top of the stack forms either "AB" or "CD". If the top is 'A' and the current character is 'B', or the top is 'C' and the current character is 'D', it pops the top character (removes the pair) and skips adding the current character. Otherwise, it pushes the current character onto the stack. This effectively removes matching pairs as they are encountered in a single pass. The final length of the stack string is the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-22 07:41 UTC
- Runtime: 24 ms
- Memory: 10.4 MB
- Language: C++
