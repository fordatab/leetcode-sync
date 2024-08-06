# Merge Sorted Array

**Difficulty:** Easy
**Tags:** two-pointers, array, sorting, merge

## Problem

Given two sorted integer arrays where the first array has enough capacity to hold both, merge the second array into the first while maintaining sorted order. The first array contains m valid elements followed by n zeros as placeholders, and the second array contains n elements. The merge must be done in-place, modifying the first array directly.

## Approach

This solution uses a three-pointer technique that fills the first array from back to front. It maintains pointers at the end of the valid portion of the first array (i), the end of the second array (j), and the current write position (idx). The algorithm repeatedly compares elements at positions i and j, placing the larger element at position idx and decrementing the appropriate pointers. The loop continues while there are elements remaining in the second array. By working backwards, we avoid overwriting unprocessed elements in the first array, eliminating the need for extra space. When the second array is exhausted, any remaining elements in the first array are already in their correct positions.

## Complexity

- **Time:** O(m + n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-06 03:28 UTC
- Runtime: 0 ms
- Memory: 11.3 MB
- Language: C++
