# Search in Rotated Sorted Array

**Difficulty:** Medium
**Tags:** binary-search, array, divide-and-conquer

## Problem

Given an array of distinct integers that was originally sorted in ascending order but may have been rotated at some unknown pivot point, find the index of a target value in logarithmic time. The array has between 1 and 5000 elements with values ranging from -10^4 to 10^4, and you must return -1 if the target is not present.

## Approach

The solution uses a modified binary search that accounts for the rotation. At each step, it calculates the middle index and checks if it's the target. If not, it determines which half of the array (left or right of mid) is properly sorted by comparing `nums[mid]` with `nums[l]`.

When the left half is sorted (`nums[mid] >= nums[l]`), the code checks if the target falls within the sorted left range. If the target is greater than mid or less than the left boundary, it searches the right half; otherwise, it searches the left half.

When the right half is sorted (the else case), the logic checks if the target falls within the sorted right range. If the target is less than mid or greater than the right boundary, it searches the left half; otherwise, it searches the right half.

This approach ensures that at each iteration, the search space is halved by intelligently choosing which side to explore based on the sorted portion and target's potential location.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-03 03:29 UTC
- Runtime: 5 ms
- Memory: 13.5 MB
- Language: C++
