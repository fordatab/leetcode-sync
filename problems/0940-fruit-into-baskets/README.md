# Fruit Into Baskets

**Difficulty:** Medium
**Tags:** sliding-window, hash-table, two-pointers, array

## Problem

Given an array representing fruit types on trees arranged in a row, find the longest contiguous subarray containing at most two distinct fruit types. You must collect fruits consecutively from left to right, and can only store two different fruit types total across your two baskets. The goal is to maximize the number of fruits collected before encountering a third type that would force you to stop.

## Approach

This solution uses a sliding window approach with a hash map to track fruit types and their counts within the current window. The algorithm maintains two pointers: `r` (right) expands the window by iterating through the array and adding each fruit type to the map with its count. When the map contains more than 2 distinct fruit types, the left pointer `l` advances, decrementing counts and removing fruit types from the map until only 2 types remain. After each adjustment, the maximum window size (`r - l + 1`) is tracked. The hash map allows efficient checking of distinct types and quick removal when counts reach zero, ensuring the window always respects the two-basket constraint.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-04-13 04:53 UTC
- Runtime: 43 ms
- Memory: 84.9 MB
- Language: C++
