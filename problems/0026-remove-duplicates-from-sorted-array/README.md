# Remove Duplicates from Sorted Array

**Difficulty:** Easy
**Tags:** two-pointers, array, in-place

## Problem

Given a sorted array of integers, modify it in-place so that each distinct value appears only once at the beginning of the array, maintaining sorted order. Return the count of unique elements. The array can contain up to 30,000 elements with values between -100 and 100.

## Approach

The solution uses a two-pointer technique where a write pointer (`l`) tracks the position for the next unique element, and a read pointer (`r`) scans through the array.

For each position of `r`, the code uses a while loop to skip over consecutive duplicate values by advancing `r` until it reaches either the last occurrence of the current value or the end of the array. Once all duplicates are skipped, the value at `r` (the last occurrence of the current unique value) is written to position `l`, and `l` is incremented.

This process continues until `r` has traversed the entire array. The write pointer `l` ends up pointing one past the last unique element, so its final value represents the count of unique elements. The debug print statements output the pointer positions and array contents during execution.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 01:08 UTC
- Runtime: 23 ms
- Memory: 21.5 MB
- Language: C++
