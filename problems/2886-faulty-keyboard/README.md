# Faulty Keyboard

**Difficulty:** Easy
**Tags:** string, simulation, string-reversal

## Problem

Given a string representing characters typed on a faulty keyboard, simulate the typing process where the character 'i' reverses the current accumulated string, while all other characters are appended normally. Return the final string after processing all input characters. The input length is at most 100 characters and consists only of lowercase English letters, with the guarantee that the first character is never 'i'.

## Approach

The solution uses a simple simulation approach with a single output string. It iterates through each character of the input string sequentially. When encountering a regular character (not 'i'), it appends the character to the output string. When encountering the character 'i', it reverses the entire output string in-place using the standard library `reverse` function. After processing all characters, the accumulated output string represents the final state of the laptop screen.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-21 07:26 UTC
- Runtime: 0 ms
- Memory: 9.8 MB
- Language: C++
