# Two Sum

**Difficulty:** Easy
**Tags:** hash-table, array, two-pointers

## Problem

Given an array of integers and a target value, find the indices of two elements that sum to the target. The array contains between 2 and 10,000 elements with values ranging from -10^9 to 10^9, and exactly one valid pair is guaranteed to exist. Each element can only be used once.

## Approach

The solution uses a hash table (unordered_map) to store previously seen numbers and their indices. As it iterates through the array, for each element it calculates the complement (target minus current element) needed to reach the target sum.

For each number encountered, the algorithm checks if its complement already exists in the hash table. If the complement is not found, it stores the current number and its index in the map for future lookups. If the complement is found, it immediately returns a vector containing the stored index of the complement and the current index.

This single-pass approach avoids the need for nested loops by trading space for time—each element is examined once, and lookups in the hash table are O(1) on average.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-27 03:23 UTC
- Runtime: 8 ms
- Memory: 14 MB
- Language: C++
