# Next Greater Element I

**Difficulty:** Easy
**Tags:** stack, hash-table, monotonic-stack, array

## Problem

Given two arrays where the first is a subset of the second, find for each element in the first array the next greater element that appears to its right in the second array. All elements in both arrays are unique, with lengths up to 1000 and values up to 10,000. Return -1 if no such greater element exists.

## Approach

The solution uses a monotonic decreasing stack combined with a hash map. It processes `nums2` from left to right: for each element, it pops all smaller elements from the stack and records the current element as their next greater element in the map. Then it pushes the current element onto the stack. Elements remaining in the stack have no next greater element. Finally, it iterates through `nums1` and replaces each element with its mapped next greater element (or -1 if not found in the map). The key insight is that when processing elements in order, the stack maintains potential candidates waiting for their next greater element, and any element being processed is the answer for all smaller stack elements.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-23 02:26 UTC
- Runtime: 0 ms
- Memory: 12.4 MB
- Language: C++
