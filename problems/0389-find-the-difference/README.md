# Find the Difference

**Difficulty:** Easy
**Tags:** bit-manipulation, xor, string

## Problem

Given two strings where the second string is a shuffled version of the first with exactly one additional character inserted at any position, identify and return that extra character. The strings consist only of lowercase English letters, with the first string having length 0 to 1000 and the second string always being exactly one character longer.

## Approach

The solution uses the XOR bitwise operator to find the added character. It initializes a result variable to 0 and XORs it with every character in both strings. Since XOR has the property that `a ^ a = 0` and `a ^ 0 = a`, all characters that appear in both strings cancel each other out (each character in `s` XORs with its corresponding character in `t`). The only character that doesn't have a pair is the extra character added to `t`, which remains after all the XOR operations complete. This elegant bit manipulation technique eliminates the need for additional data structures like hash maps or sorting.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 09:08 UTC
- Runtime: 0 ms
- Memory: 8.1 MB
- Language: C++
