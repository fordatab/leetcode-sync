# Lexicographically Smallest String After a Swap

**Difficulty:** Easy
**Tags:** string, greedy, two-pointer

## Problem

Given a string of digits, find the lexicographically smallest string obtainable by swapping at most one pair of adjacent digits that share the same parity (both odd or both even). The string has length between 2 and 100 characters.

## Approach

The solution uses a greedy single-pass approach. It iterates through the string from left to right, checking each pair of adjacent characters. For each pair, it determines if both digits have the same parity by comparing their remainders when divided by 2. When it finds the first adjacent pair with matching parity where the right digit is smaller than the left digit, it performs the swap and immediately breaks out of the loop. This greedy strategy works because swapping earlier positions has greater impact on lexicographic ordering, and we want the smallest possible digit as far left as possible. If no beneficial swap is found, the original string is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 02:45 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
