# Longest Repeating Character Replacement

**Difficulty:** Medium
**Tags:** sliding-window, two-pointers, hash-table, string

## Problem

Given a string of uppercase English letters and an integer k, find the length of the longest substring that can be made to contain all identical characters by changing at most k characters. The string has length up to 10^5, and k ranges from 0 to the string length.

## Approach

This solution uses a sliding window technique with a character frequency array. It maintains a window [l, r] and tracks the count of each character in the current window using a 26-element array.

For each position r, it increments the count of the character at that position. The key insight is that a valid window can have at most k replacements, meaning the window size minus the count of the most frequent character should not exceed k.

When the window becomes invalid (i.e., `window_size - max_frequency > k`), it shrinks from the left by incrementing l and decrementing the count of the leftmost character. The condition `r - l - *max_element(chars, chars+26) + 1 > k` checks if the number of characters that would need to be replaced exceeds k.

The maximum window size encountered is tracked and returned as the answer. Note that this implementation recalculates the maximum frequency using `max_element` on each iteration rather than maintaining it separately.

## Complexity

- **Time:** O(n * 26) = O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-10 21:39 UTC
- Runtime: 8 ms
- Memory: 8.2 MB
- Language: C++
