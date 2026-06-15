# 3Sum Closest

**Difficulty:** Medium
**Tags:** two-pointers, sorting, array

## Problem

Given an array of integers and a target value, find three distinct elements whose sum is closest to the target. The array contains between 3 and 500 elements with values ranging from -1000 to 1000, and the target ranges from -10,000 to 10,000. Return the actual sum of these three integers, with the guarantee that exactly one solution exists.

## Approach

The solution uses a sorting and two-pointer technique. First, the array is sorted in ascending order. Then, for each element at index `i`, the problem is reduced to finding two elements in the remaining sorted subarray whose sum (plus `nums[i]`) is closest to the target.

For each fixed first element `nums[i]`, two pointers `l` and `r` are initialized to the positions immediately after `i` and at the end of the array. A new target is computed as `target - nums[i]`, and the algorithm searches for the pair whose sum is closest to this new target.

At each step, the current three-element sum is compared against the best sum found so far by tracking the minimum absolute difference. The two pointers are moved based on whether the current pair sum is less than or equal to the new target (move left pointer right) or greater (move right pointer left), efficiently exploring all possible pairs for each fixed first element.

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-15 04:09 UTC
- Runtime: 15 ms
- Memory: 14.1 MB
- Language: C++
