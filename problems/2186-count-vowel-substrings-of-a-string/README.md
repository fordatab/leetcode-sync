# Count Vowel Substrings of a String

**Difficulty:** Easy
**Tags:** sliding-window, hash-table, two-pointers, string

## Problem

Given a string of lowercase letters, count how many contiguous substrings consist exclusively of vowels (a, e, i, o, u) and contain at least one occurrence of each of the five vowels. The string can be up to 100 characters long.

## Approach

The solution uses a sliding window technique with two left pointers (L1 and L2) and one right pointer (R). As the right pointer scans through the string, any consonant triggers a complete reset of the window state. For vowel characters, the code maintains a frequency map and tracks the count of distinct vowels currently in the window.

When all five vowels are present (cnt == 5), the L2 pointer advances to shrink the window until one vowel type is completely removed, ensuring the window between L2 and R has exactly four distinct vowels. The key insight is that any substring starting from L1 up to (but not including) L2 and ending at R will contain all five vowels, since L2 marks the point where removing one more character would lose a vowel type.

For each position R, the number of valid substrings ending at R is (L2 - L1), representing all possible starting positions that yield valid vowel substrings. This count is accumulated into the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-11-30 04:38 UTC
- Runtime: 0 ms
- Memory: 8.5 MB
- Language: C++
