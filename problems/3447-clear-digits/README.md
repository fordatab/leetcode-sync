# Clear Digits

**Difficulty:** Easy
**Tags:** string, stack, simulation

## Problem

Given a string containing lowercase letters and digits, repeatedly remove digits by deleting each digit along with the closest non-digit character to its left. The string is guaranteed to allow complete removal of all digits. Return the final string after all digits are removed.

## Approach

The solution uses a stack-like approach with a string as the container. It iterates through the input string character by character. When a digit is encountered (checked via `c <= '9'`, which works because digits come before letters in ASCII), the algorithm removes the most recently added non-digit character by popping from the output string. When a non-digit character is encountered, it's simply added to the output string. This simulates the removal operation efficiently in a single pass, where the output string acts as a stack maintaining the characters that haven't been paired with digits yet.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-22 07:30 UTC
- Runtime: 0 ms
- Memory: 8 MB
- Language: C++
