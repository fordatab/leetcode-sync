# Minimum Array Length After Pair Removals

**Difficulty:** Medium
**Tags:** binary-search, greedy, two-pointers, array

## Problem

Given a sorted array of integers, you can repeatedly remove any two elements at positions i and j where the value at i is strictly less than the value at j. The goal is to determine the minimum possible array length after performing this operation optimally. The array can contain duplicate values, and elements must have different values to be paired for removal.

## Approach

The solution uses binary search to find the maximum number of pairs that can be removed. The key insight is that if we can remove k pairs, we should pair the k smallest elements with the k largest elements. The `check` function verifies whether k pairs can be removed by comparing the first k elements with elements starting at position `n-k`, ensuring each element in the first group is strictly less than its corresponding element in the second group. Binary search explores values of k from 0 to n/2 (the theoretical maximum number of pairs), and the answer is the original length minus twice the maximum valid k.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2025-12-04 01:57 UTC
- Runtime: 6 ms
- Memory: 153 MB
- Language: C++
