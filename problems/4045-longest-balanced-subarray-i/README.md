# Longest Balanced Subarray I

**Difficulty:** Medium
**Tags:** hash-table, sliding-window, two-pointers, brute-force

## Problem

Given an integer array, find the longest contiguous subarray where the count of distinct even numbers equals the count of distinct odd numbers. The array can have up to 1500 elements, with values ranging from 1 to 100,000.

## Approach

This solution uses a brute-force approach with nested loops to examine every possible subarray. For each starting position `i`, it iterates through all ending positions `k` from `i` to the end of the array. Two hash maps track distinct even and odd numbers encountered so far in the current subarray: as each element is processed, it's added to either the `even` or `odd` map based on its parity. After adding each element, if the sizes of both maps are equal (meaning equal counts of distinct evens and odds), the current subarray length `k - i + 1` is compared against the maximum length found so far. This approach checks all O(n²) subarrays, maintaining the distinct counts incrementally within the inner loop.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-26 06:25 UTC
- Runtime: 1860 ms
- Memory: 530.6 MB
- Language: C++
