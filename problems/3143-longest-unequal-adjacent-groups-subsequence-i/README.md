# Longest Unequal Adjacent Groups Subsequence I

**Difficulty:** Easy
**Tags:** greedy, array, string

## Problem

Given parallel arrays of strings and binary group labels (both length n), find the longest subsequence where consecutive elements have different group values. The task is to select words such that no two adjacent selections share the same group label (0 or 1). All strings in the input are distinct, and arrays have length between 1 and 100.

## Approach

The solution uses a greedy single-pass approach. It iterates through the input arrays from left to right, maintaining a result vector. For each position, it includes the current word if either it's the first element or its group value differs from the previous element's group. This works because whenever we encounter a group change, we can safely extend our subsequence—skipping such an element would never lead to a longer valid sequence. The algorithm essentially removes consecutive duplicates from the groups array while collecting the corresponding words.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-05 01:26 UTC
- Runtime: 0 ms
- Memory: 28.9 MB
- Language: C++
