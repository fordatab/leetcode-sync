# Partition Array According to Given Pivot

**Difficulty:** Medium
**Tags:** array, two-pointers, sorting

## Problem

Given an array and a pivot value, rearrange the array into three sections: elements less than the pivot, elements equal to the pivot, and elements greater than the pivot. The relative order of elements within each section (less than and greater than) must be preserved. The array size can be up to 100,000 elements, with values ranging from -1,000,000 to 1,000,000.

## Approach

The solution uses a three-pass approach with auxiliary arrays:

1. **First pass**: Iterate through the input array once, separating elements into two vectors - `l` for elements less than the pivot and `r` for elements greater than the pivot. Elements equal to the pivot are counted implicitly.

2. **Second pass**: Calculate how many elements equal the pivot by subtracting the sizes of `l` and `r` from the total array size. Append that many pivot values to the end of vector `l`.

3. **Third pass**: Append all elements from vector `r` to the end of vector `l`, which now contains all three sections in the correct order.

The solution maintains relative order naturally because elements are pushed to `l` and `r` in the order they appear during the initial scan. The final result is returned as vector `l`, which has been built up to contain all elements properly partitioned.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-26 00:20 UTC
- Runtime: 138 ms
- Memory: 135.4 MB
- Language: C++
