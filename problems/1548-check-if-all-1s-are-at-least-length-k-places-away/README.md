# Check If All 1's Are at Least Length K Places Away

**Difficulty:** Easy
**Tags:** array, single-pass, greedy

## Problem

Given a binary array and an integer k, determine whether every pair of consecutive 1s in the array has at least k zeros between them. The array can have up to 10^5 elements, and k can range from 0 to the array length.

## Approach

The solution uses a single-pass scan with a tracking variable `prev` that stores the index of the most recently encountered 1. Initially, `prev` is set to `-k-1` to handle the edge case where the first 1 appears early in the array without triggering a false negative. As we iterate through the array, whenever we find a 1 at index `x`, we calculate the distance to the previous 1 as `x - prev - 1` (the number of elements between them). If this distance is less than k, we immediately return false. Otherwise, we update `prev` to the current index and continue. If we complete the scan without finding any violations, we return true.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-02 02:37 UTC
- Runtime: 67 ms
- Memory: 60.3 MB
- Language: C++
