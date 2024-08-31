# Minimum Size Subarray Sum

**Difficulty:** Medium
**Tags:** sliding-window, two-pointers, array, greedy

## Problem

Given an array of positive integers and a target value, find the shortest contiguous subarray whose sum is at least the target. The array can contain up to 100,000 elements with values up to 10,000 each, and the target can be as large as 1 billion. Return 0 if no valid subarray exists.

## Approach

This solution uses a sliding window (two-pointer) technique with left and right pointers initially at the start of the array. The algorithm maintains a running sum of elements in the current window.

The main loop advances the right pointer when the current sum is below the target, adding elements to expand the window. When the sum meets or exceeds the target, it records the current window length as a candidate answer and then shrinks the window from the left by removing elements and advancing the left pointer.

After the right pointer reaches the end of the array, a second loop continues shrinking the window from the left while the sum still meets the target, ensuring all valid minimal windows are considered. The minimum window length seen throughout this process is tracked and returned, or 0 if no valid window was found.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-31 01:53 UTC
- Runtime: 209 ms
- Memory: 31 MB
- Language: C++
