# Combination Sum

**Difficulty:** Medium
**Tags:** backtracking, recursion, array, combinatorics

## Problem

Given an array of distinct positive integers and a target sum, find all unique combinations of numbers from the array that sum to the target. Each number can be reused unlimited times in a combination. The input array has at most 30 elements with values between 2 and 40, and the target is between 1 and 40.

## Approach

The solution uses recursive backtracking to explore all possible combinations. At each recursive step, it makes two choices: either include the current candidate number (and stay at the same index to allow reuse) or skip it and move to the next candidate.

The base cases are: if the target becomes zero, the current combination is valid and added to results; if the index goes out of bounds or the target becomes negative, the search backtracks.

For each candidate at index `i`, the algorithm first tries including it by adding it to the current combination and recursively calling with the reduced target (`target - nums[i]`) while keeping the same index `i` (allowing repeated use). After exploring that branch, it backtracks by removing the number and then explores the branch where that candidate is skipped entirely by incrementing to `i + 1`.

This exhaustively generates all valid combinations without duplicates, since the index only moves forward when skipping candidates, ensuring each unique combination is found exactly once.

## Complexity

- **Time:** O(2^t)
- **Space:** O(t)

## Stats

- Submitted: 2024-07-22 10:08 UTC
- Runtime: 0 ms
- Memory: 12.6 MB
- Language: C++
