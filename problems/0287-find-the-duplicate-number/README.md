# Find the Duplicate Number

**Difficulty:** Medium
**Tags:** hash-table, array

## Problem

Given an array of n+1 integers where each value is between 1 and n inclusive, find the single number that appears more than once. All other numbers appear exactly once. The solution must use constant extra space and cannot modify the input array.

## Approach

This solution uses a hash table to track which numbers have been seen while iterating through the array. For each element, it checks if the element exists in the map (has a non-zero count). If the element hasn't been seen before, it increments its count to 1. If the element has already been seen (count is non-zero), it immediately returns that element as the duplicate. The algorithm makes a single pass through the array and returns as soon as the first duplicate is found.

Note: While this approach solves the problem correctly, it does not satisfy the constant space constraint mentioned in the problem statement, as the hash map can grow proportionally with the input size.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-12 22:45 UTC
- Runtime: 126 ms
- Memory: 87.9 MB
- Language: C++
