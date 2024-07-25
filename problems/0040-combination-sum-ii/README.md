# Combination Sum II

**Difficulty:** Medium
**Tags:** backtracking, recursion, array, sorting

## Problem

Given an array of candidate numbers and a target sum, find all unique combinations of candidates that sum to the target. Each candidate number can be used at most once per combination, and the input may contain duplicate values. The constraint is that the candidates array has up to 100 elements with values 1-50, and the target is at most 30.

## Approach

The solution uses backtracking with pruning to explore all possible combinations. First, the candidates array is sorted to enable efficient duplicate handling. The recursive DFS function maintains the current combination and remaining target. At each level, it iterates through candidates starting from the current index, skipping duplicates at the same recursion level by tracking the previous value. When a candidate is chosen, it's added to the current combination, and the function recurses with the next index and reduced target. If the target reaches zero, a valid combination is found and added to results. If the target becomes negative, the branch is pruned. After exploring each candidate, it's removed from the current combination (backtracking). The key insight is that sorting combined with the `prev` variable prevents duplicate combinations by ensuring that identical values at the same recursion depth are only processed once.

## Complexity

- **Time:** O(2^n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 23:57 UTC
- Runtime: 0 ms
- Memory: 12.9 MB
- Language: C++
