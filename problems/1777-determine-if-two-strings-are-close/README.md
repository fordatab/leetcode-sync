# Determine if Two Strings Are Close

**Difficulty:** Medium
**Tags:** hash-table, string, frequency-counting, greedy

## Problem

Given two strings consisting of lowercase English letters, determine whether they can be made identical through any combination of two operations: swapping any two characters within a string, or swapping all occurrences of one character with all occurrences of another character (both transformations applied simultaneously). The strings must be of equal length, and each operation can be applied any number of times to either string.

## Approach

The solution first checks if both strings have the same length, returning false immediately if not. It then builds frequency maps for each string, counting occurrences of each character (indexed by their offset from 'a'). If these frequency maps are identical, the strings are already equal and the function returns true.

If the frequency maps differ, the code checks two conditions: First, it verifies that both strings contain exactly the same set of characters (if a character appears in one string, it must appear in the other, even if with different frequencies). This ensures Operation 2 can only swap between characters that exist in both strings.

Second, it builds "frequency-of-frequencies" maps (c1 and c2) that count how many characters appear with each frequency. For example, if three characters each appear twice, the frequency-of-frequencies map would have an entry mapping 2→3. The strings are close if and only if these frequency-of-frequencies distributions match, because Operation 2 allows us to reassign which specific characters have which frequencies, as long as the multiset of frequencies remains the same.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-20 06:26 UTC
- Runtime: 111 ms
- Memory: 23.6 MB
- Language: C++
