# Maximum Value at a Given Index in a Bounded Array

**Difficulty:** Medium
**Tags:** binary-search, greedy, math, array

## Problem

Given an array length n, a specific index, and a maximum allowed sum, construct an array where all elements are positive integers, adjacent elements differ by at most 1, and the total sum doesn't exceed maxSum. The goal is to maximize the value at the given index position. The constraints allow n and maxSum up to 10^9, making direct array construction impractical.

## Approach

The solution uses binary search on the answer space to find the maximum possible value at the target index. For each candidate value `mid`, it checks whether an array can be constructed with that peak value at the index while respecting the sum constraint.

The key insight is that to minimize the total sum while maximizing the value at `index`, the array should form a "pyramid" shape centered at that index, decreasing by 1 in each direction until reaching 1. The `sideSum` helper computes the sum of elements on one side of the peak: if the side is long enough, it forms an arithmetic sequence; otherwise, it includes some 1's after the sequence ends.

The `check` function calculates the total sum as: the peak value plus the left side sum (from peak-1) plus the right side sum (from peak-1). Binary search narrows down to the largest value where this total doesn't exceed maxSum.

The search range is [1, maxSum], and the algorithm maintains the best valid answer found, returning it once the binary search completes.

## Complexity

- **Time:** O(log maxSum)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-04 11:48 UTC
- Runtime: 0 ms
- Memory: 8.1 MB
- Language: C++
