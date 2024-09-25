# Minimum Number of Steps to Make Two Strings Anagram

**Difficulty:** Medium
**Tags:** hash-table, frequency-counting, string, array

## Problem

Given two equal-length strings s and t containing only lowercase English letters, determine the minimum number of character replacements needed in string t to make it an anagram of s. The strings can be up to 50,000 characters long, and a replacement allows changing any character in t to any other character.

## Approach

The solution uses a frequency-counting approach with a single array of size 128 (covering all ASCII characters). It iterates through both strings simultaneously, incrementing the counter for each character in s and decrementing it for each character in t. This produces a net frequency difference for each character: positive values indicate excess characters in s (deficits in t), while negative values indicate excess characters in t. The algorithm then sums the absolute values of all negative frequencies, which represents the count of characters in t that need to be replaced. Since each replacement in t can fix one character mismatch, this sum equals the minimum number of steps required.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 04:34 UTC
- Runtime: 42 ms
- Memory: 18 MB
- Language: C++
