# Find the Highest Altitude

**Difficulty:** Easy
**Tags:** array, prefix-sum, greedy

## Problem

Given an array representing altitude changes between consecutive points on a road trip (starting at altitude 0), find the maximum altitude reached at any point. The array has length n (1 ≤ n ≤ 100) with values in the range [-100, 100], representing net gains or losses in altitude between adjacent points.

## Approach

The solution transforms the gain array into a cumulative sum array in-place, where each element represents the absolute altitude at that point. It iterates through the array from index 1 onward, adding each element to the previous cumulative sum. After converting all gains to altitudes, it finds the maximum value in the array using `max_element`. Since the starting altitude (0) is not stored in the array, the code checks if the maximum altitude in the array is negative; if so, it returns 0 (the starting point), otherwise it returns the maximum found.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-16 08:42 UTC
- Runtime: 0 ms
- Memory: 10.1 MB
- Language: C++
