# Find All Anagrams in a String

**Difficulty:** Medium
**Tags:** sliding-window, hash-table, string, frequency-counter

## Problem

Given two strings s and p (both consisting of lowercase English letters with lengths up to 30,000), find all starting positions in s where a substring of length equal to p forms an anagram of p. An anagram means the substring contains exactly the same characters with the same frequencies as p, though possibly in a different order.

## Approach

The solution uses a sliding window technique with two hash maps to track character frequencies. First, it builds a frequency map of all characters in the pattern string p. Then it maintains a sliding window of size p.length() that moves across string s from left to right.

For each position, the code adds the current character to the window's frequency map. When the window reaches the target size, it compares the window's frequency map with the pattern's frequency map using direct map equality comparison. If they match, the current window starting position is added to the result.

After each comparison, the window slides forward by removing the leftmost character (decrementing its count and erasing it from the map if the count reaches zero) and incrementing the left pointer. This maintains a constant window size equal to the pattern length throughout the iteration.

## Complexity

- **Time:** O(n * k)
- **Space:** O(k)

## Stats

- Submitted: 2024-09-16 08:07 UTC
- Runtime: 37 ms
- Memory: 15.4 MB
- Language: C++
