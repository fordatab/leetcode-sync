# Two Sum

**Difficulty:** Easy
**Tags:** array, nested-loops, brute-force

## Problem

Given an array of integers and a target sum, find the indices of two distinct elements that add up to the target. The input is guaranteed to have exactly one valid pair, and the array can contain between 2 and 10,000 elements with values ranging from -10^9 to 10^9.

## Approach

This solution uses a brute-force nested loop approach. The outer loop iterates through each element in the array using index `i`, while the inner loop starts at `i+1` and checks every subsequent element at index `j`. For each pair of indices, the code checks if the sum of `nums[i]` and `nums[j]` equals the target. When a matching pair is found, the function immediately returns an array containing both indices. If no pair is found after examining all combinations, an empty array is returned (though this case should never occur given the problem constraints).

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-08 05:51 UTC
- Runtime: 142 ms
- Memory: 49.5 MB
- Language: JavaScript
