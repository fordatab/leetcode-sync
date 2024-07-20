# Subsets

**Difficulty:** Medium
**Tags:** backtracking, recursion, depth-first-search, bit-manipulation-concept

## Problem

Given an array of distinct integers with at most 10 elements (each between -10 and 10), generate all possible subsets including the empty set. The order of subsets in the result doesn't matter, and no duplicates should appear since all input elements are unique.

## Approach

This solution uses a depth-first search (DFS) backtracking approach to build all subsets. Starting with an empty subset, it recursively explores two choices at each position: include the current element or exclude it. At each recursive call indexed by `i`, the algorithm first adds `nums[i]` to the current subset and recurses to position `i+1`, then backtracks by removing that element and recurses again to `i+1` without it. When the index reaches or exceeds the array size, the current subset (whether empty or partially filled) is added to the result. This exhaustively generates all 2^n possible subsets by exploring every combination of include/exclude decisions.

## Complexity

- **Time:** O(n * 2^n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-20 05:51 UTC
- Runtime: 4 ms
- Memory: 8.6 MB
- Language: C++
