# Count Sorted Vowel Strings

**Difficulty:** Medium
**Tags:** dynamic-programming, combinatorics, math

## Problem

Given a positive integer n (1 ≤ n ≤ 50), determine how many strings of length n can be formed using only the five vowels (a, e, i, o, u) such that each string is non-decreasing when read left to right. A string is non-decreasing if each character is the same as or comes after the previous character in alphabetical order.

## Approach

The solution uses a 2D dynamic programming table where `dp[i][j]` represents the count of valid strings of length `j` that end with the i-th vowel (indexed 0-4 for a, e, i, o, u respectively).

Base case: For strings of length 1, there's exactly one string ending with each vowel, so all `dp[i][1]` are initialized to 1.

Recurrence: For each position from 2 to n, the number of strings ending with vowel `i` equals the sum of strings from the previous position that end with vowel `i` or any earlier vowel. This is because to maintain lexicographic order, we can only append a vowel that's greater than or equal to the last character. For example, strings ending in 'e' can be formed by appending 'e' to any string ending in 'a' or 'e'.

Finally, the solution sums up all entries `dp[i][n]` for i from 0 to 4 to get the total count of valid strings of length n.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-07 00:33 UTC
- Runtime: 3 ms
- Memory: 7.8 MB
- Language: C++
