# Add Binary

**Difficulty:** Easy
**Tags:** string, bit-manipulation, simulation, math

## Problem

Given two binary strings of length up to 10,000 digits, compute their sum and return it as a binary string. Each input string contains only '0' and '1' characters with no leading zeros except when representing zero itself.

## Approach

The solution simulates elementary-school addition by processing digits from right to left with a carry. It uses the input strings themselves as stacks, repeatedly extracting the last character from each string via `back()` and removing it with `pop_back()`. At each step, it converts characters to integers, computes the sum of the two current digits plus any carry, appends the result modulo 2 to the output string, and updates the carry by dividing the sum by 2. When one string is exhausted, it continues with the remaining string, treating the empty one as providing 0. After both strings are processed, if a carry remains, it appends that carry to the output. Finally, the output string is reversed since digits were added in reverse order.

## Complexity

- **Time:** O(max(n, m))
- **Space:** O(max(n, m))

## Stats

- Submitted: 2024-08-13 03:25 UTC
- Runtime: 16 ms
- Memory: 8.1 MB
- Language: C++
