# Minimum Absolute Difference Between Elements With Constraint

**Difficulty:** Medium
**Tags:** sliding-window, binary-search, ordered-set, greedy

## Problem

Given an array of integers and a minimum separation distance x, find the smallest absolute difference between any two elements whose indices are at least x positions apart. The array can contain up to 100,000 elements with values up to 1 billion, and x ranges from 0 to the array length minus one.

## Approach

The solution uses a sliding window approach with a balanced binary search tree (set). As we iterate through the array starting from index x, we maintain a set of all elements that are at least x indices behind the current position. For each element at index i, we first insert the element at index i-x into the set (making it eligible for pairing), then use binary search to find the closest values in the set.

Specifically, `lower_bound` finds the smallest element greater than or equal to the current element. We check both this element (if it exists) and its predecessor in the set (if it exists), computing the absolute differences and tracking the minimum. This works because in a sorted structure, the closest values to a target are either the immediate successor or immediate predecessor.

The set automatically maintains sorted order, allowing efficient O(log n) insertion and lookup operations. By processing elements left to right and only considering previously seen elements that satisfy the distance constraint, we ensure all valid pairs are examined exactly once.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-03 00:51 UTC
- Runtime: 95 ms
- Memory: 124.1 MB
- Language: C++
