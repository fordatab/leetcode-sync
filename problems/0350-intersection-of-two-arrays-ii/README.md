# Intersection of Two Arrays II

**Difficulty:** Easy
**Tags:** hash-table, array, frequency-counting

## Problem

Given two integer arrays, find their intersection where each element appears in the result as many times as it appears in both input arrays. The arrays can contain up to 1000 elements each, with values ranging from 0 to 1000, and the result order doesn't matter.

## Approach

The solution uses a frequency-counting approach with a hash map. First, it iterates through the first array (`nums1`) and records the count of each element in an unordered map. Then, it iterates through the second array (`nums2`), and for each element, checks if it exists in the map with a positive count. If so, it decrements the count in the map and adds the element to the result vector. This ensures each element appears in the intersection only as many times as it appears in both arrays, since the count is limited by the frequency in `nums1` and can only be decremented as many times as the element appears in `nums2`.

## Complexity

- **Time:** O(n + m)
- **Space:** O(min(n, m))

## Stats

- Submitted: 2024-09-14 05:16 UTC
- Runtime: 5 ms
- Memory: 14.7 MB
- Language: C++
