# To Lower Case

**Difficulty:** Easy
**Tags:** string, bit-manipulation, ascii

## Problem

Given a string containing printable ASCII characters with length between 1 and 100, convert all uppercase letters to their lowercase equivalents and return the modified string. Characters that are already lowercase or non-alphabetic remain unchanged.

## Approach

The solution iterates through each character in the input string by reference. For each character, it checks whether it falls within the uppercase ASCII range ('A' to 'Z'). If so, it applies a bitwise OR operation with the binary value 0b00100000 (decimal 32), which flips the 6th bit. In ASCII encoding, uppercase and lowercase letters differ by exactly this bit position—uppercase letters have this bit as 0, while lowercase letters have it as 1. By setting this bit to 1, any uppercase letter is converted to its lowercase equivalent. The modified string is then returned. This in-place modification approach avoids allocating additional memory for a new string.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 00:38 UTC
- Runtime: 3 ms
- Memory: 7.7 MB
- Language: C++
