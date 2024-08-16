# Count Pairs Whose Sum is Less than Target

**Difficulty:** Easy
**Tags:** two-pointers, sorting, array

## Problem

Given an array of integers and a target value, count how many distinct pairs of indices (i, j) exist where i < j and the sum of the elements at those indices is strictly less than the target. The array can have up to 50 elements with values ranging from -50 to 50.

## Approach

The solution uses a two-pointer technique on a sorted array. First, the input array is sorted in ascending order. Two pointers are initialized: one at the start (l) and one at the end (r) of the array.

The algorithm repeatedly checks if the sum of elements at the two pointers is less than the target. If it is, all pairs between the left pointer and positions from l+1 to r form valid pairs (since the array is sorted, if nums[l] + nums[r] < target, then nums[l] + nums[k] < target for all k where l < k ≤ r). The count is incremented by (r - l), and the left pointer moves right.

If the sum is not less than the target, the right pointer moves left to try a smaller value. This continues until the pointers meet, at which point all valid pairs have been counted.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-16 03:17 UTC
- Runtime: 7 ms
- Memory: 24 MB
- Language: C++
