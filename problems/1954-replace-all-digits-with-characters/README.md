# Replace All Digits with Characters

**Difficulty:** Easy
**Tags:** string, simulation, ascii-manipulation

## Problem

Given a string where even indices contain lowercase letters and odd indices contain digits, replace each digit at odd index i with the character that appears x positions after the letter at index i-1, where x is the digit's numeric value. The string length is at most 100, and all shift operations are guaranteed to stay within the lowercase alphabet range.

## Approach

The solution iterates through the string character by character, maintaining a `prev` variable that tracks the most recently processed character. When encountering a digit, it computes the shifted character by adding the digit's numeric value (obtained via `c - '0'`) to the ASCII value of the previous character, then replaces the digit with this result. After processing each character (whether letter or now-replaced digit), it updates `prev` to that character. This single-pass approach modifies the string in-place and correctly handles the alternating letter-digit pattern.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 07:26 UTC
- Runtime: 0 ms
- Memory: 7.6 MB
- Language: C++
