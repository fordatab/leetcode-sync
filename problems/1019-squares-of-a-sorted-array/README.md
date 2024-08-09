# Squares of a Sorted Array

**Difficulty:** Easy
**Tags:** two-pointers, array, sorting

## Problem

Given an array of integers sorted in non-decreasing order, return a new array containing the squares of each element, also sorted in non-decreasing order. The input array can contain negative numbers, which when squared may produce larger values than squared positive numbers. The array length can be up to 10,000 elements with values ranging from -10,000 to 10,000.

## Approach

The solution uses a two-pointer technique to build the result array in reverse order. It places pointers at both ends of the input array (left at index 0, right at the last index). Since the input is sorted, the largest squared values must come from either end (either large negative numbers on the left or large positive numbers on the right).

At each step, the algorithm compares the absolute values of the elements at both pointers. It squares and appends the element with the larger absolute value to the output array, then moves that pointer inward. This process continues until all elements are processed.

Finally, since the algorithm builds the result from largest to smallest (appending the larger squares first), it reverses the entire output array to achieve non-decreasing order. The key insight is that in a sorted array containing both negative and positive numbers, the extremes (far left and far right) always contain the largest absolute values.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-09 02:48 UTC
- Runtime: 19 ms
- Memory: 29.6 MB
- Language: C++
