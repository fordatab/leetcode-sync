# Maximum Average Subarray I

**Difficulty:** Easy
**Tags:** sliding-window, array

## Problem

Given an integer array of n elements and an integer k, find the contiguous subarray of exactly length k that has the maximum average value. The array can contain negative values ranging from -10^4 to 10^4, and k is guaranteed to be between 1 and n (where n can be up to 10^5).

## Approach

This solution uses a sliding window technique to efficiently find the maximum sum among all subarrays of length k, then converts that sum to an average.

The algorithm maintains a window using two pointers (l for left, r for right) and tracks the running sum of elements in the current window. As the right pointer iterates through the array, elements are added to the total. When the window reaches size k (checked via `r - l + 1 == k`), the current sum is compared against the maximum sum seen so far, then the left element is removed from the total and the left pointer advances.

By maintaining only the sum rather than recalculating it for each window, the solution avoids redundant additions. The maximum sum is tracked using a long integer (initialized to INT_MIN to handle negative sums), and at the end, it's divided by k and cast to double to produce the maximum average.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-13 02:40 UTC
- Runtime: 329 ms
- Memory: 112.4 MB
- Language: C++
