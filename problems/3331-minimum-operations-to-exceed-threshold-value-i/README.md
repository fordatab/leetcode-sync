# Minimum Operations to Exceed Threshold Value I

**Difficulty:** Easy
**Tags:** array, counting, iteration

## Problem

Given an array of integers and a threshold value k, determine how many elements are less than k. Each operation removes one element below the threshold, and the goal is to find the minimum number of operations needed so all remaining elements are at least k. The input guarantees at least one element is already greater than or equal to k.

## Approach

The solution iterates through the entire array once, counting how many elements are strictly less than k. Since we need to remove all elements below the threshold to satisfy the condition that all remaining elements are at least k, the count of such elements directly gives us the minimum number of operations required. The code uses a simple counter that increments whenever an element less than k is encountered, then returns this count.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:33 UTC
- Runtime: 4 ms
- Memory: 24.4 MB
- Language: C++
