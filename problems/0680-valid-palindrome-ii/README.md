# Valid Palindrome II

**Difficulty:** Easy
**Tags:** two-pointers, string, greedy

## Problem

Given a string of lowercase English letters with length up to 100,000, determine whether it can form a palindrome by removing at most one character. The task is to return true if the string is already a palindrome or can become one after a single deletion, and false otherwise.

## Approach

The solution uses a two-pointer approach starting from both ends of the string. It compares characters from the left and right, moving the pointers inward while they match. When a mismatch is found, the algorithm tries two possibilities: either skip the left character or skip the right character. For each possibility, it checks if the remaining substring forms a valid palindrome using a helper function that performs standard two-pointer palindrome validation. If either skipping option results in a palindrome, the function returns true. If no mismatch is encountered during the initial scan, the string is already a palindrome and returns true.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-02 23:40 UTC
- Runtime: 3 ms
- Memory: 22.1 MB
- Language: C++
