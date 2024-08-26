# Best Time to Buy and Sell Stock with Transaction Fee

**Difficulty:** Medium
**Tags:** dynamic-programming, array, state-machine

## Problem

Given an array of daily stock prices and a fixed transaction fee, determine the maximum profit achievable through any number of buy-sell transactions, where you must sell before buying again and pay the fee once per complete transaction. The array can contain up to 50,000 elements, with prices and fees up to 50,000.

## Approach

This solution uses dynamic programming with two state arrays traversed backward from the last day to the first. The `hold` array tracks the maximum profit when currently holding stock (after accounting for the transaction fee on the eventual sale), while the `buy` array tracks the maximum profit when not holding stock and available to buy. At each day `x`, `hold[x]` is the maximum of either keeping the previous `hold` state or selling at the current price (minus fee) plus the future `buy` profit. Similarly, `buy[x]` is the maximum of either keeping the previous `buy` state or buying at the current price (negative cost) plus the future `hold` profit. The arrays are initialized at position `n` with base cases, and the final answer is `buy[0]`, representing the maximum profit starting from day 0 with no stock held.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-26 08:28 UTC
- Runtime: 335 ms
- Memory: 62.4 MB
- Language: C++
