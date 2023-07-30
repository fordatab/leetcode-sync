# Two Sum

**Difficulty:** Easy
**Tags:** array, brute-force, nested-loops

## Problem

Given an array of integers and a target sum, find the indices of two distinct elements that add up to the target. The problem guarantees exactly one solution exists, and the same element cannot be used twice. The array can contain up to 10,000 elements with values ranging from -10^9 to 10^9.

## Approach

This solution uses a nested loop approach to check all possible pairs of elements. The outer loop iterates through each element at index `i`, while the inner loop examines all elements that come after it by creating a slice `nums2 = nums[i+1:]`. For each pair, it checks if their sum equals the target. When a matching pair is found, it returns the indices `[i, i+j+1]`, where `i+j+1` accounts for the offset created by the slice starting at position `i+1`. This is a brute-force solution with quadratic time complexity.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2023-07-30 01:53 UTC
- Runtime: 2202 ms
- Memory: 14.3 MB
- Language: Python
