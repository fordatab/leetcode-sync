# Smallest Range Covering Elements from K Lists

**Difficulty:** Hard
**Tags:** sliding-window, hash-table, sorting, two-pointers, greedy

## Problem

Given k sorted lists of integers, find the smallest range [a, b] that contains at least one element from each list. A range is considered smaller if its length is shorter, or if lengths are equal, the one with the smaller starting point is chosen. Each list has 1-50 elements, k can be up to 3500, and values range from -10^5 to 10^5.

## Approach

The solution flattens all k lists into a single array of value-list_index pairs, then sorts this merged array by value. It uses a sliding window approach with two pointers to find the minimum range. A hash map tracks how many elements from each list are currently in the window. The right pointer expands the window by including elements until all k lists are represented (tracked by a counter). Once all lists are covered, the left pointer contracts the window by removing elements while maintaining coverage, updating the best range whenever a smaller valid window is found. This process continues until all elements have been processed.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-19 11:15 UTC
- Runtime: 63 ms
- Memory: 54.7 MB
- Language: C++
