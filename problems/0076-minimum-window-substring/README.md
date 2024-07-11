# Minimum Window Substring

**Difficulty:** Hard
**Tags:** sliding-window, two-pointers, hash-table, string

## Problem

Find the shortest contiguous substring in string s that contains all characters from string t, including duplicates. The input strings s and t have lengths up to 10^5 and consist of English letters. If no such substring exists, return an empty string.

## Approach

The solution uses a sliding window technique with two pointers (left and right). It maintains two frequency arrays: `a` tracks the required count of each character from `t`, and `b` tracks the current count in the window. The variable `count` represents the number of distinct characters needed, and `have` tracks how many we've satisfied.

The right pointer expands the window by iterating through `s`. When a character's count in `b` matches its required count in `a`, we increment `have`. Once all required characters are satisfied (`have == count`), the left pointer contracts the window to find the minimum length. During contraction, we update the minimum window if a shorter valid window is found, then decrement the frequency and move left forward. If removing a character breaks the validity condition (a required character falls below its needed count), we decrement `have` and stop contracting.

The algorithm tracks the start position and minimum length of the valid window found, returning the substring if one exists, otherwise an empty string.

## Complexity

- **Time:** O(m + n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 02:40 UTC
- Runtime: 7 ms
- Memory: 10.1 MB
- Language: C++
