# Median of Two Sorted Arrays

**Difficulty:** Hard
**Tags:** binary-search, array, divide-and-conquer, two-pointers

## Problem

Find the median of two sorted arrays without merging them explicitly, maintaining O(log(m+n)) time complexity. The arrays can have sizes from 0 to 1000 each (with at least one non-empty), and elements range from -10^6 to 10^6. The median should be computed as the middle element for odd total length, or the average of two middle elements for even total length.

## Approach

The solution uses binary search on the smaller of the two arrays to partition both arrays such that all elements on the left side are less than or equal to all elements on the right side.

First, it handles edge cases where one array is empty, directly computing the median from the non-empty array. Then it ensures binary search runs on the smaller array (swapping if needed) for efficiency.

The key insight is finding a partition point `mid` in the first array and corresponding point `mid_2` in the second array such that `mid + mid_2 = half` (where `half = (total+1)/2`). For each partition attempt, it compares the boundary elements: the rightmost elements of the left partitions (`a_l`, `b_l`) and leftmost elements of the right partitions (`a_r`, `b_r`).

If `a_l <= b_r` and `b_l <= a_r`, a valid partition is found. For odd total length, the median is the maximum of the left partition maximums. For even total length, it's the average of the maximum left element and minimum right element. If the partition is invalid (e.g., `a_l > b_r`), binary search adjusts by moving the partition point left or right accordingly.

## Complexity

- **Time:** O(log(min(m, n)))
- **Space:** O(1)

## Stats

- Submitted: 2024-07-04 02:59 UTC
- Runtime: 25 ms
- Memory: 94.4 MB
- Language: C++
