# Sliding Window Maximum

**Difficulty:** Hard
**Tags:** sliding-window, deque, monotonic-queue, array

## Problem

Given an integer array and a window size k, slide a window of size k from left to right across the array, one position at a time. For each window position, determine the maximum element within that window. The array can contain up to 100,000 elements with values ranging from -10,000 to 10,000, and k is guaranteed to be at most the array length.

## Approach

The solution uses a monotonic decreasing deque to efficiently track potential maximum values. The deque stores indices (not values) of array elements in decreasing order of their corresponding values.

As we iterate through the array, we first remove the front index if it's outside the current window (more than k positions behind). Then we maintain the monotonic property by removing all indices from the back whose values are smaller than the current element, since they can never be maximums while the current element is in the window. We then add the current index to the back.

Once the window reaches size k (when `x + 1 >= k`), the front of the deque always contains the index of the maximum element in the current window. We append `nums[d.front()]` to the result array. This approach avoids recalculating the maximum for each window by maintaining useful candidates in the deque.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-11 03:24 UTC
- Runtime: 165 ms
- Memory: 137.2 MB
- Language: C++
