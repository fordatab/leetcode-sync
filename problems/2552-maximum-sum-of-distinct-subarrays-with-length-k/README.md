# Maximum Sum of Distinct Subarrays With Length K

**Difficulty:** Medium
**Tags:** sliding-window, hash-table, array

## Problem

Given an array of integers and a window size k, find the maximum sum among all contiguous subarrays of exactly length k where all elements are unique. If no such subarray exists, return 0. The array can contain up to 100,000 elements with values up to 100,000.

## Approach

This solution uses a sliding window approach with a hashmap to track element frequencies. It maintains a window of size k by expanding from the right and contracting from the left. As elements enter the window on the right, they're added to both the running sum and a frequency map. When the window reaches size k, it checks if all elements are distinct by verifying that the hashmap size equals k (meaning each element appears exactly once). If so, it updates the maximum sum. The window then slides forward by removing the leftmost element from both the sum and the map, decrementing its frequency and erasing it if the count reaches zero. This process continues until all possible k-length windows are examined.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2026-03-05 04:37 UTC
- Runtime: 95 ms
- Memory: 95.4 MB
- Language: C++
