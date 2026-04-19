# Identify the Largest Outlier in an Array

**Difficulty:** Medium
**Tags:** hash-table, math, frequency-counting, array

## Problem

Given an array of n integers, exactly n-2 elements are "special numbers", one element equals the sum of those special numbers, and one element is an "outlier" (neither a special number nor the sum). The task is to find the largest possible value that could be the outlier. Elements at different indices can have the same value, and the array length ranges from 3 to 10^5 with values between -1000 and 1000.

## Approach

The solution uses a frequency map and total sum to test each element as a potential outlier. For each element considered as the outlier, the remaining elements should consist of n-2 special numbers and their sum. If the outlier is removed, the sum of remaining elements must be even (since half would be the sum element, and half would be the actual sum of special numbers). The code checks if `(total_sum - candidate_outlier) / 2` exists in the frequency map. A special case handles when the candidate outlier value equals the potential sum value—in this case, the frequency must be greater than 1 to use distinct indices. The algorithm tracks the maximum valid outlier found across all candidates.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-19 06:58 UTC
- Runtime: 87 ms
- Memory: 184.4 MB
- Language: C++
