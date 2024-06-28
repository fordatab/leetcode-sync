# Longest Consecutive Sequence

**Difficulty:** Medium
**Tags:** hash-table, union-find, array, greedy

## Problem

Given an unsorted array of integers, find the length of the longest sequence of consecutive integers that can be formed from the array elements. The algorithm must achieve linear time complexity. The array can contain up to 100,000 elements with values ranging from -10^9 to 10^9, and may include duplicates.

## Approach

The solution uses an unordered set to store all unique elements from the input array. It then iteratively processes elements by:

1. Inserting all array elements into a hash set for O(1) lookups
2. While the set is not empty, selecting an arbitrary element as a starting point
3. From that element, expanding bidirectionally: first incrementing to find all consecutive larger values, then decrementing from the original to find all consecutive smaller values
4. Removing each visited element from the set to avoid reprocessing
5. Tracking the maximum sequence length encountered

The key insight is that by removing elements as they're visited, each element is processed exactly once. The bidirectional expansion from each unvisited element ensures we find the complete consecutive sequence containing that element, even when starting from the middle of a sequence.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-28 03:18 UTC
- Runtime: 141 ms
- Memory: 74.4 MB
- Language: C++
