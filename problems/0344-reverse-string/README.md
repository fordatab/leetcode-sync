# Reverse String

**Difficulty:** Easy
**Tags:** two-pointers, array, string

## Problem

Given an array of characters, reverse it in place without using additional memory beyond O(1). The array contains between 1 and 100,000 printable ASCII characters, and the reversal must modify the original array directly rather than creating a new one.

## Approach

The solution uses a two-pointer technique to reverse the array in place. It initializes two pointers: one at the beginning (l) and one at the end (r) of the array. In each iteration of the while loop, it swaps the characters at these two positions using the built-in swap function, then moves the left pointer forward and the right pointer backward. The loop continues until the pointers meet or cross in the middle, at which point the entire array has been reversed. This approach modifies the array directly without allocating any additional data structures proportional to the input size.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 23:04 UTC
- Runtime: 24 ms
- Memory: 27.3 MB
- Language: C++
