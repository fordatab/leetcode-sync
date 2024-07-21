# Removing Stars From a String

**Difficulty:** Medium
**Tags:** stack, string, simulation

## Problem

Given a string containing lowercase letters and asterisks, process each asterisk by removing it along with the nearest non-asterisk character to its left. Return the resulting string after all asterisks have been processed. The input guarantees that every asterisk will have at least one character to its left, and the string length can be up to 100,000 characters.

## Approach

The solution uses a stack to simulate the removal process. It iterates through the input string character by character. When encountering a regular letter, it pushes the letter onto the stack. When encountering an asterisk, it pops the top element from the stack (removing the most recently added non-star character). After processing all characters, the stack contains the remaining characters in reverse order. The solution builds the output string by popping all elements from the stack and then reverses this string to restore the correct order before returning it.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-21 07:44 UTC
- Runtime: 83 ms
- Memory: 28.5 MB
- Language: C++
