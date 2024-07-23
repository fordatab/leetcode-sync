# Max Consecutive Ones III

**Difficulty:** Medium
**Tags:** sliding-window, two-pointers, array

## Problem

Given a binary array and an integer k, find the length of the longest contiguous subarray that contains only 1s after flipping at most k zeros to ones. The array can have up to 100,000 elements, and k can range from 0 to the array length.

## Approach

This solution uses a sliding window approach with two pointers (left and right). The right pointer expands the window by iterating through the array, tracking the count of zeros and ones separately. When the count of zeros exceeds k, the left pointer advances to shrink the window until the zero count is valid again. Throughout this process, it maintains the maximum count of ones seen. Finally, it returns either the maximum ones count plus k (representing the flipped zeros) or the entire array length, whichever is smaller. The separate tracking of ones and zeros allows the solution to calculate the window size indirectly.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 06:36 UTC
- Runtime: 42 ms
- Memory: 58.1 MB
- Language: C++
