# Longest Substring with At Least K Repeating Characters

**Difficulty:** Medium
**Tags:** sliding-window, hash-table, two-pointers, string

## Problem

Find the length of the longest substring where every character appears at least k times. The input is a string containing only lowercase English letters (length up to 10^4) and an integer k (up to 10^5). If no valid substring exists, return 0.

## Approach

The solution uses a sliding window approach with an outer loop that iterates over all possible counts of unique characters (1 to the total number of unique characters in the string). For each target count of unique characters:

- Maintain a two-pointer sliding window with a hash map tracking character frequencies
- Expand the window (move right pointer) when the current unique character count is at or below the target
- Shrink the window (move left pointer) when unique character count exceeds the target
- Track two metrics: the number of unique characters in the current window and how many of those characters meet the frequency threshold of k
- When both metrics equal the target unique count (meaning all characters in the window appear at least k times), update the maximum length

The key insight is that by fixing the number of unique characters allowed in the window, we can use a standard sliding window technique to efficiently find valid substrings, then iterate through all possible unique character counts to find the global maximum.

## Complexity

- **Time:** O(n * u)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-17 03:58 UTC
- Runtime: 19 ms
- Memory: 8.9 MB
- Language: C++
