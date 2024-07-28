# Decode Ways

**Difficulty:** Medium
**Tags:** dynamic-programming, memoization, string, recursion

## Problem

Given a string of digits, determine how many distinct ways it can be decoded into letters, where '1' maps to 'A', '2' to 'B', through '26' to 'Z'. A digit can be decoded individually (if it's 1-9) or paired with the next digit (if the pair forms 10-26). Leading zeros make a sequence invalid, and the string length can be up to 100 characters.

## Approach

The solution uses top-down dynamic programming with memoization. Starting from index 0, it recursively explores two decoding options at each position: decode one digit (if not '0') or decode two digits (if they form a valid number between 10 and 26). The base case sets the number of ways to decode an empty suffix (index == s.size()) as 1. A hashmap caches results for each index to avoid redundant calculations. If the current character is '0', it returns 0 immediately since standalone '0' cannot be decoded. Otherwise, it adds the ways from decoding one character ahead, and if applicable, adds the ways from decoding two characters ahead when the current and next digits form '10'-'19' or '20'-'26'.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-28 06:50 UTC
- Runtime: 3 ms
- Memory: 11.7 MB
- Language: C++
