# Longest Subarray of 1's After Deleting One Element

**Difficulty:** Medium
**Tags:** sliding-window, two-pointers, array

## Problem

Given a binary array, you must remove exactly one element and then find the longest contiguous subarray consisting only of 1s in the resulting array. The array can have up to 100,000 elements. If the array contains all 1s, removing one element means the answer is the array length minus one.

## Approach

This solution uses a sliding window technique with two pointers. The window expands by moving the right pointer through the array while tracking the count of zeros (`z_ct`) and ones (`m`) in the current window. When more than one zero is encountered, the left pointer advances until at most one zero remains in the window. The maximum count of ones seen in any valid window (containing at most one zero) becomes the answer. A special case handles arrays of all 1s: since exactly one element must be deleted, the final answer is decremented if it equals the array length.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 06:27 UTC
- Runtime: 334 ms
- Memory: 58.8 MB
- Language: C++
