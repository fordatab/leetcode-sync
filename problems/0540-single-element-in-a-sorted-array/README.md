# Single Element in a Sorted Array

**Difficulty:** Medium
**Tags:** binary-search, array, sorted-array, index-parity

## Problem

Given a sorted array where every element appears exactly twice except for one element that appears once, find and return that single element. The array length is between 1 and 100,000, and the solution must achieve O(log n) time complexity and O(1) space complexity.

## Approach

The solution uses binary search to locate the unique element. A helper function `check` determines whether the element at a given index matches its left neighbor (returning 3), right neighbor (returning 2), or neither (returning 0, indicating it's the single element).

The key insight is that in a sorted array with pairs, before the single element all pairs start at even indices (0, 2, 4...), and after the single element this pattern breaks. When the middle element matches its right neighbor and starts at an even index, the single element must be to the right. When it matches its right neighbor but starts at an odd index, the pattern is already broken, so the single element is to the left.

Similarly, when the middle element matches its left neighbor and the pair started at an even index (mid-1 is even), the pattern is still intact and the target is to the right. If the pair started at an odd index, the pattern is broken and the target is to the left. The search continues by adjusting the left and right pointers until they converge on the single element.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2025-12-02 12:39 UTC
- Runtime: 0 ms
- Memory: 26.3 MB
- Language: C++
