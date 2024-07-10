# Permutation in String

**Difficulty:** Medium
**Tags:** sliding-window, hash-table, string, array

## Problem

Given two strings s1 and s2, determine whether s2 contains any substring that is a permutation of s1. Both strings consist only of lowercase English letters with lengths up to 10,000. A permutation means any arrangement of s1's characters, so the substring must have the exact same character frequencies as s1.

## Approach

The solution uses a sliding window approach with character frequency counting. It maintains two frequency arrays of size 26 (for lowercase letters): one (`c`) stores the target frequencies from s1, and another (`chars`) tracks the current window in s2.

The algorithm slides a window of size equal to s1's length across s2. For each position, it adds the rightmost character to the window and removes the leftmost character when the window exceeds the target size. After each adjustment, it compares all 26 frequency counts between the two arrays.

If at any point the frequency arrays match completely (all 26 positions are equal), a permutation has been found and the function returns true. If the entire s2 is traversed without finding a match, it returns false.

## Complexity

- **Time:** O(n * 26)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-10 23:11 UTC
- Runtime: 3 ms
- Memory: 8.4 MB
- Language: C++
