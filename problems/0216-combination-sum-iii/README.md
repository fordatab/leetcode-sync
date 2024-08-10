# Combination Sum III

**Difficulty:** Medium
**Tags:** backtracking, recursion, depth-first-search, combination

## Problem

Given two integers k and n, find all combinations of exactly k distinct numbers from the range 1 to 9 that sum to n. Each number can be used at most once in a combination, and the result should contain all unique valid combinations without duplicates.

## Approach

This solution uses backtracking with depth-first search to explore all possible combinations. Starting from number 1, it recursively tries adding each candidate number from the current position up to 9 to the partial combination. At each step, it maintains the remaining sum needed and the count of numbers already selected.

The base cases handle termination: when exactly k numbers have been selected and the sum equals zero, the combination is valid and added to the results. If k numbers are reached without achieving the target sum, or if the sum goes negative, the search backtracks.

The key insight is using parameter `x` to track the next candidate number, ensuring each number is considered only once and in ascending order (passing `i + 1` in the recursive call). After exploring with a number included, it's removed from the current combination (backtracking) to try other possibilities.

## Complexity

- **Time:** O(C(9,k))
- **Space:** O(k)

## Stats

- Submitted: 2024-08-10 02:17 UTC
- Runtime: 3 ms
- Memory: 8.1 MB
- Language: C++
