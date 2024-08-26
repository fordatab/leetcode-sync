# Best Time to Buy and Sell Stock II

**Difficulty:** Medium
**Tags:** dynamic-programming, greedy, array, state-machine

## Problem

Given an array of daily stock prices, find the maximum profit achievable through multiple buy-sell transactions where you can hold at most one share at a time. You can buy and sell on the same day, and the goal is to accumulate the highest total profit across all transactions. The array can contain up to 30,000 elements with prices ranging from 0 to 10,000.

## Approach

The solution uses dynamic programming with a backward iteration approach. It maintains four state variables: `buy_0` and `hold_0` representing the maximum profit at the current day when either buying (not holding stock before) or holding stock, and `buy_1` and `hold_1` representing these states for the next day.

Starting from the last day and moving backward, at each position the algorithm computes two choices: the best profit if we buy stock at this price (choosing between buying now at `-prices[x]` plus future profit from holding, or skipping this day), and the best profit if we hold stock through this day (choosing between continuing to hold or selling now at `prices[x]` plus future profit from the buy state).

The states are updated in a rolling fashion where today's computed states become tomorrow's reference states. The final answer `buy_0` represents the maximum profit achievable starting from day 0 when we don't initially hold stock, which is the answer to the problem.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-26 21:10 UTC
- Runtime: 3 ms
- Memory: 15.9 MB
- Language: C++
