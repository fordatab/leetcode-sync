# Palindrome Partitioning

**Difficulty:** Medium
**Tags:** backtracking, string, recursion, two-pointer, dynamic-programming

## Problem

Given a string of up to 16 lowercase English letters, find all possible ways to partition it such that every substring in each partition is a palindrome. Return all valid partitionings as a list of lists of strings.

## Approach

The solution uses backtracking to explore all possible partitionings. Starting from index 0, it tries every possible substring beginning at the current position. For each substring, it checks if it's a palindrome using a two-pointer technique that compares characters from both ends moving inward. If a substring is a palindrome, it's added to the current partition, and the algorithm recursively continues from the next index. When the end of the string is reached, the current partition is added to the results. After exploring each path, the algorithm backtracks by removing the last added substring to try other possibilities. This exhaustive search ensures all valid palindrome partitionings are found.

## Complexity

- **Time:** O(n * 2^n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-26 08:21 UTC
- Runtime: 69 ms
- Memory: 53 MB
- Language: C++
