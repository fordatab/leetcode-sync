# Next Permutation

**Difficulty:** Medium
**Tags:** array, two-pointers, greedy, permutation

## Problem

Given an array of integers, rearrange it in-place to produce the next lexicographically larger permutation. If the array is already the largest permutation (descending order), wrap around to the smallest permutation (ascending order). The solution must use constant extra space and modify the array directly.

## Approach

The solution implements the standard next permutation algorithm with a three-step process:

1. **Find the pivot**: Scan from right to left to find the longest non-increasing suffix. The element just before this suffix (at index `i-1`) is the pivot—the rightmost position where we can make a lexicographically larger change.

2. **Handle edge case**: If no such pivot exists (the entire array is non-increasing), we've reached the last permutation, so reverse the entire array to get the smallest permutation.

3. **Swap and reverse**: Find the smallest element in the suffix that is larger than the pivot (scanning from the right), swap it with the pivot, then reverse the suffix to get the next smallest lexicographic arrangement.

This approach works because the suffix is always in descending order, making the rightmost swap candidate easy to find and ensuring the reversal produces the minimal arrangement for that prefix.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-16 05:53 UTC
- Runtime: 0 ms
- Memory: 14.9 MB
- Language: C++
