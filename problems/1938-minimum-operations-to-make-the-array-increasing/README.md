# Minimum Operations to Make the Array Increasing

**Difficulty:** Easy
**Tags:** array, greedy, simulation

## Problem

Given a zero-indexed integer array, determine the minimum number of increment-by-one operations needed to make the array strictly increasing, where each element must be strictly less than the next. The array can have length 1 to 5000, with elements ranging from 1 to 10,000.

## Approach

The solution uses a greedy single-pass approach. It iterates through the array from the second element onward, and whenever it finds an element that is less than or equal to its predecessor, it calculates how many increments are needed to make it exactly one greater than the previous element. The code computes the difference `nums[x-1] - nums[x] + 1`, adds this value to the current element to update it in-place, and accumulates the total operations needed. By processing left-to-right and immediately fixing violations, each position only needs to be adjusted once, ensuring all subsequent comparisons use the corrected values.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 20:26 UTC
- Runtime: 8 ms
- Memory: 18.5 MB
- Language: C++
