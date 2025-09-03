# K-diff Pairs in an Array

**Difficulty:** Medium
**Tags:** two-pointers, sorting, array

## Problem

Find the count of unique pairs of integers in an array where the absolute difference between the two values equals a given target k. Pairs are considered unique based on their values (not indices), so duplicate numbers in the array should only contribute once. The array can contain up to 10,000 elements with values ranging from -10^7 to 10^7, and k ranges from 0 to 10^7.

## Approach

The solution employs a two-pointer technique on a sorted array. First, the input array is sorted to enable efficient pair detection. Two pointers `l` (left) and `r` (right) traverse the array, where `r` is always advanced to find a position where `nums[r] - nums[l]` equals k.

The algorithm works by:
- Advancing `r` forward until the difference `nums[r] - nums[l]` is at least k
- If the difference exceeds k, advancing `l` forward to reduce the gap
- When an exact match is found (difference equals k and indices differ), incrementing the count and skipping all duplicate values of `nums[r]` to ensure uniqueness
- The outer loop continues advancing `r` through the entire array

Duplicate handling is crucial: after finding a valid pair, the code skips all elements equal to the current `nums[r]` value to avoid counting duplicate pairs, which ensures only unique value-pairs are counted.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2025-09-03 00:15 UTC
- Runtime: 0 ms
- Memory: 15.1 MB
- Language: C++
