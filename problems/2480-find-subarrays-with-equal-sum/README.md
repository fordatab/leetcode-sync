# Find Subarrays With Equal Sum

**Difficulty:** Easy
**Tags:** sliding-window, hash-table, array

## Problem

Given an integer array, determine if there exist two different consecutive pairs of elements (subarrays of length 2) that have the same sum. The pairs must start at different indices. The array has between 2 and 1000 elements, with values ranging from -10^9 to 10^9.

## Approach

The solution uses a sliding window of size 2 combined with a hash map to track encountered sums. It initializes a variable `a` with the first element, then iterates through the array starting from index 1. At each position, it adds the current element to `a` to form a two-element sum, records this sum in a hash map, and checks if this sum has been seen before (count equals 2). If a duplicate sum is found, it immediately returns true. After checking, it slides the window forward by subtracting the element at position `x-1` from `a`. If no duplicate sums are found after checking all possible consecutive pairs, it returns false.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-24 03:06 UTC
- Runtime: 3 ms
- Memory: 10.2 MB
- Language: C++
