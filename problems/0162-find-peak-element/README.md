# Find Peak Element

**Difficulty:** Medium
**Tags:** binary-search, array

## Problem

Given an array where each element must be strictly different from its neighbors, find any index where the element is greater than both adjacent elements. Elements outside the array bounds are treated as negative infinity. The algorithm must run in logarithmic time, and the array can have 1 to 1000 elements with values in the 32-bit integer range.

## Approach

The solution uses binary search to locate a peak in logarithmic time. It handles edge cases upfront: single-element arrays return index 0, and two-element arrays return the index of the larger element.

For larger arrays, the algorithm maintains left and right pointers and repeatedly examines the middle element. If the middle element is at a boundary (index 0 or the last index), it handles those cases specially. Otherwise, it checks if the middle element is greater than both neighbors—if so, it's a peak and the index is returned.

The key insight is the search direction: if `nums[mid] > nums[mid-1]`, the algorithm moves right (sets `l = mid + 1`) because there must be a peak in the ascending direction. Otherwise, it moves left (sets `r = mid - 1`). This guarantees finding a peak because the boundary conditions ensure at least one peak exists, and moving toward the ascending side always leads to one.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-29 07:25 UTC
- Runtime: 3 ms
- Memory: 11.5 MB
- Language: C++
