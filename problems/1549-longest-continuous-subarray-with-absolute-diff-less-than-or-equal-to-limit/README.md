# Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

**Difficulty:** Medium
**Tags:** sliding-window, multiset, ordered-set, two-pointers

## Problem

Find the length of the longest contiguous subarray where the difference between the maximum and minimum elements does not exceed a given limit. The array contains up to 100,000 integers, each between 1 and 10^9, and the limit can be as large as 10^9.

## Approach

The solution uses a sliding window technique with a multiset to track the minimum and maximum values in the current window. As the right pointer expands the window by iterating through the array, each element is inserted into the multiset. The multiset automatically maintains sorted order, allowing constant-time access to the minimum (*s.begin()) and maximum (*s.rbegin()) values.

When the difference between max and min exceeds the limit, the left pointer advances by repeatedly removing the leftmost elements from both the window and the multiset until the constraint is satisfied again. The multiset's find() and erase() operations ensure only one occurrence is removed at a time, which is important when duplicates exist.

At each step, the solution updates the maximum subarray length by taking the current size of the multiset, which represents the number of elements in the valid window. This approach guarantees that every valid window is considered.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-08-31 07:21 UTC
- Runtime: 2496 ms
- Memory: 117.7 MB
- Language: C++
