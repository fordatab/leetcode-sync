# Count Ways To Build Good Strings

**Difficulty:** Medium
**Tags:** dynamic-programming, combinatorics, counting

## Problem

We need to count distinct strings that can be built by repeatedly appending either 'zero' zeros or 'one' ones to an initially empty string. A valid string must have a length between 'low' and 'high' inclusive. The answer should be returned modulo 10^9 + 7, with constraints allowing lengths up to 100,000.

## Approach

This solution uses dynamic programming where `dp[i]` represents the number of ways to construct a string of exactly length `i`. Starting with `dp[0] = 1` (one way to have an empty string), we iterate through all possible lengths from 1 to `high`. At each length `i`, we can reach it by either:

- Adding `zero` zeros to a string of length `i - zero` (if valid)
- Adding `one` ones to a string of length `i - one` (if valid)

The number of ways to construct a string of length `i` is the sum of ways to construct strings of lengths `i - zero` and `i - one`. After computing allDP values, we sum up `dp[i]` for all `i` in the range `[low, high]` to get the total count of good strings. All operations are done modulo 10^9 + 7 to prevent overflow.

## Complexity

- **Time:** O(high)
- **Space:** O(high)

## Stats

- Submitted: 2026-07-13 19:14 UTC
- Runtime: 0 ms
- Memory: 11.7 MB
- Language: C++
