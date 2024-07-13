# Maximum Number of Vowels in a Substring of Given Length

**Difficulty:** Medium
**Tags:** sliding-window, string, two-pointers

## Problem

Given a string and an integer k, find the maximum count of vowel characters (a, e, i, o, u) that appear in any contiguous substring of exactly length k. The string contains only lowercase English letters and has a length up to 100,000.

## Approach

The solution uses a sliding window technique to maintain a window of exactly k characters. It starts with two pointers (l for left, r for right) and a counter c for the current number of vowels in the window. As the right pointer iterates through the string, it increments the vowel count when encountering a vowel. When the window reaches size k (checked by r - l + 1 == k), it updates the maximum vowel count seen so far, then slides the window forward by removing the leftmost character (decrementing the count if it's a vowel) and advancing the left pointer. A helper function `isvowel` checks if a character is one of the five vowels. This approach ensures each substring of length k is examined exactly once.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-13 08:45 UTC
- Runtime: 19 ms
- Memory: 11.4 MB
- Language: C++
