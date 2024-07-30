# Coin Change

**Difficulty:** Medium
**Tags:** dynamic-programming, array, bottom-up-dp, coin-change

## Problem

Given an array of coin denominations and a target amount, find the minimum number of coins needed to make up that amount, assuming unlimited supply of each denomination. If the amount cannot be formed, return -1. Constraints include up to 12 coin types, coin values up to 2^31 - 1, and target amounts up to 10,000.

## Approach

This solution uses bottom-up dynamic programming with a 1D array. It initializes a `dp` array of size `amount + 1` where `dp[i]` represents the minimum coins needed to make amount `i`. Each position is initially set to `amount + 1` (representing infinity), except `dp[0]` which is 0 (zero coins needed for zero amount).

The algorithm iterates through each amount from 0 to the target, and for each amount, tries using each available coin denomination. If a coin value `c` is less than or equal to the current amount `x`, it updates `dp[x]` by taking the minimum of its current value and `1 + dp[x - c]` (one coin plus the minimum coins needed for the remaining amount).

After filling the entire dp table, it checks if `dp[amount]` still holds the impossible sentinel value (greater than `amount`). If so, it returns -1; otherwise, it returns the computed minimum number of coins.

## Complexity

- **Time:** O(amount × coins.length)
- **Space:** O(amount)

## Stats

- Submitted: 2024-07-30 01:18 UTC
- Runtime: 15 ms
- Memory: 16.4 MB
- Language: C++
