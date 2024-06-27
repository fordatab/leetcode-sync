# Contains Duplicate

**Difficulty:** Easy
**Tags:** hash-table, array, set

## Problem

Given an array of integers, determine whether any value appears more than once. The array can contain up to 100,000 elements with values ranging from -10^9 to 10^9. Return true if duplicates exist, false if all elements are unique.

## Approach

The solution uses an unordered set to detect duplicates efficiently. It constructs the set by inserting all elements from the input array using the range constructor. Since a set only stores unique values, any duplicates in the original array will be collapsed into single entries. The code then compares the size of the set against the size of the original array — if they differ, at least one duplicate must have existed. This single-pass construction with immediate size comparison provides a clean and concise solution.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-27 02:31 UTC
- Runtime: 115 ms
- Memory: 75.2 MB
- Language: C++
