# Search in Rotated Sorted Array II

**Difficulty:** Medium
**Tags:** array, linear-search

## Problem

Given an integer array that was originally sorted in non-decreasing order (possibly with duplicates) and then rotated at an unknown pivot point, determine whether a target value exists in the array. The array has up to 5000 elements with values ranging from -10^4 to 10^4, and the goal is to minimize the number of operations needed.

## Approach

The submitted solution uses a simple linear search approach. It iterates through every element in the input array sequentially and checks if each element equals the target value. If a match is found at any point during the iteration, the function immediately returns true. If the entire array is traversed without finding the target, the function returns false. This approach ignores the sorted and rotated properties of the array and treats it as an unsorted collection.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-03 03:30 UTC
- Runtime: 7 ms
- Memory: 16.4 MB
- Language: C++
