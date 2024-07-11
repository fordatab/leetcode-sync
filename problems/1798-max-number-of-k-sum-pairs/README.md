# Max Number of K-Sum Pairs

**Difficulty:** Medium
**Tags:** hash-table, greedy, two-pointer, counting

## Problem

Given an integer array and a target sum k, find the maximum number of pairs of elements that sum to k. Each pair can be removed from the array, and the goal is to count how many such removal operations can be performed. The array can contain up to 100,000 elements with values up to 10^9.

## Approach

The solution uses a hash map to track the frequency of each element in the array. It first populates the map by counting occurrences of all numbers. Then it iterates through the array again, and for each element, it tries to find its complement (k minus the current element). For each number encountered, it decrements its count in the map, checks if the complement exists with positive count, and if so, increments the operation counter and decrements the complement's count. If no valid complement is found, it restores the current element's count. This greedy approach pairs elements as they're encountered, using the frequency map to avoid reusing already-paired elements.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-11 06:09 UTC
- Runtime: 150 ms
- Memory: 76.5 MB
- Language: C++
