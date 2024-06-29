# Search Insert Position

**Difficulty:** Easy
**Tags:** binary-search, array, search

## Problem

Given a sorted array of unique integers and a target value, find the index of the target if it exists in the array. If the target is not present, determine the position where it should be inserted to maintain sorted order. The array can contain up to 10,000 elements with values ranging from -10,000 to 10,000, and the solution must run in logarithmic time.

## Approach

The solution uses binary search to efficiently locate the target or its insertion position. It maintains two pointers, `low` and `high`, initially set to 0 and the array size respectively.

Before entering the main loop, it checks if the target exceeds the last element in the array, immediately returning the position after the last element if true.

The binary search loop calculates the midpoint and compares the middle element with the target. If they match, it returns the middle index. If the target is smaller than the middle element, the search continues in the left half by moving `high` to `mid - 1`. Otherwise, it searches the right half by moving `low` to `mid + 1`.

When the loop terminates (when `low` exceeds `high`), the `low` pointer naturally points to the correct insertion position, which is returned as the result.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-29 11:12 UTC
- Runtime: 0 ms
- Memory: 12.1 MB
- Language: C++
