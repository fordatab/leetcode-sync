# Max Consecutive Ones

**Difficulty:** Easy
**Tags:** array, sliding-window, greedy

## Problem

Given an array containing only 0s and 1s with length up to 100,000, find the length of the longest contiguous sequence of 1s. The array must contain at least one element.

## Approach

The solution uses a single-pass linear scan with two integer counters. It maintains `cur` to track the current streak of consecutive 1s, and `ct` to store the maximum streak seen so far. As we iterate through each element: if it's a 1, we increment the current streak counter; if it's a 0, we reset the current streak to 0. After processing each element, we update the maximum by comparing it with the current streak. This greedy approach works because we only need to track the best result encountered during the traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-01-21 11:44 UTC
- Runtime: 0 ms
- Memory: 50.2 MB
- Language: C++
