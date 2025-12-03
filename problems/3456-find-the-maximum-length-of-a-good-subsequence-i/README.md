# Find the Maximum Length of a Good Subsequence I

**Difficulty:** Medium
**Tags:** dynamic-programming, hash-table, subsequence, greedy

## Problem

Given an integer array and a non-negative integer k, find the maximum length of a subsequence where at most k adjacent pairs have different values. In other words, we can tolerate up to k "transitions" between consecutive elements in the subsequence, where a transition occurs when seq[i] != seq[i+1].

## Approach

The solution uses dynamic programming with two complementary data structures. It maintains `dp[c][val]`, which tracks the maximum subsequence length ending with value `val` using at most `c` transitions, and `maxLen[c]`, which stores the overall best length for exactly `c` transitions regardless of ending value.

For each number in the input array, the algorithm iterates through transition counts from k down to 0 (reverse order prevents using the same element multiple times in one iteration). For each transition budget `c`, it considers two cases:

1. **Extend same-value subsequence**: Increment the length of subsequences ending with the current number (no new transition needed)
2. **Create transition**: If `c > 0`, take the best subsequence with `c-1` transitions (ending with any different value) and append the current number, creating one new transition

After processing each number, it updates `maxLen[c]` to track the global maximum for that transition budget. The final answer is `maxLen[k]`, representing the longest subsequence using at most k transitions.

## Complexity

- **Time:** O(n * k * m)
- **Space:** O(k * m)

## Stats

- Submitted: 2025-12-03 12:31 UTC
- Runtime: 12 ms
- Memory: 27 MB
- Language: C++
