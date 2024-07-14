# Find Target Indices After Sorting Array

**Difficulty:** Easy
**Tags:** sorting, array, linear-search

## Problem

Given an integer array and a target value, sort the array in non-decreasing order and return all indices where the target value appears. The array has at most 100 elements with values between 1 and 100. If the target doesn't exist after sorting, return an empty list.

## Approach

The solution follows a straightforward two-step process:

1. **Sort the input array** using the standard library sort function to arrange elements in non-decreasing order.

2. **Linear scan for matches**: Iterate through the sorted array from index 0 to the end, checking each element against the target value. Whenever a match is found, append that index to the result vector.

Since the array is already sorted, all occurrences of the target will be consecutive, and the indices are naturally collected in increasing order. The result vector is built incrementally during the scan and returned once complete.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-14 21:47 UTC
- Runtime: 4 ms
- Memory: 14.6 MB
- Language: C++
