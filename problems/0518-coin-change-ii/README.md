# Coin Change II

**Difficulty:** Medium
**Tags:** dynamic-programming, unbounded-knapsack, combinatorics, array

## Problem

Given an array of coin denominations and a target amount, count how many distinct combinations of coins sum to that amount. Each coin type can be used an unlimited number of times. The coin array has up to 300 unique denominations (values 1-5000), and the target amount ranges from 0 to 5000.

## Approach

This solution uses a 2D dynamic programming approach where `dp[i][x]` represents the number of ways to make amount `x` using coins from index `i` onwards.

The DP table is initialized with `dp[i][0] = 1` for all coin indices, since there's exactly one way to make amount 0 (use no coins). The algorithm then iterates through each amount from 1 to the target, and for each amount, processes coins in reverse order (from last to first).

For each position `dp[i][x]`, it accumulates two values: first, all the ways to make amount `x` without using coin `i` (carried from `dp[i+1][x]`), and second, if the current coin value doesn't exceed the amount, it adds the number of ways to make the remaining amount `x - coins[i]` while still allowing the current coin to be reused (`dp[i][x-coins[i]]`).

The reverse iteration through coins ensures that each coin index accumulates results from coins with higher indices first, building up the complete solution. The final answer at `dp[0][amount]` represents all combinations using any subset of the available coins.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n * m)

## Stats

- Submitted: 2024-08-26 03:06 UTC
- Runtime: 13 ms
- Memory: 20 MB
- Language: C++
