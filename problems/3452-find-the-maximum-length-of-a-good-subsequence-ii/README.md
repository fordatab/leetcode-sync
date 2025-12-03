# Find the Maximum Length of a Good Subsequence II

**Difficulty:** Hard
**Tags:** dynamic-programming, hash-table, subsequence, optimization

## Problem

Given an integer array and a non-negative integer k, find the longest subsequence where at most k consecutive pairs of elements have different values. In other words, a subsequence is "good" if there are at most k positions i where seq[i] ≠ seq[i+1]. The array can have up to 5000 elements with values up to 10^9, and k is bounded by min(50, array length).

## Approach

The solution uses dynamic programming with two tracking structures. It maintains `dp[c][val]`, which stores the maximum subsequence length ending with value `val` using at most `c` transitions (consecutive unequal pairs), and `maxLen[c]`, which tracks the overall best length for exactly `c` transitions regardless of ending value.

For each number in the input, the algorithm processes all change counts from k down to 0 (reverse order prevents double-counting the same element). At each step, it considers two scenarios: extending a subsequence that already ends with the current number (no new transition), or attaching the current number to the best subsequence with one fewer transition (creating a new transition).

The key insight is that when adding a number different from the previous ending value, we can look up the global best for c-1 transitions via `maxLen[c-1]` rather than checking all possible ending values individually. After processing each number, the algorithm updates the global maximum for each transition count. The final answer is `maxLen[k]`, representing the longest good subsequence with at most k transitions.

## Complexity

- **Time:** O(n * k * m)
- **Space:** O(k * m)

## Stats

- Submitted: 2025-12-03 09:39 UTC
- Runtime: 322 ms
- Memory: 128.2 MB
- Language: C++
