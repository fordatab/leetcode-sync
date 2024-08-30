# Best Time to Buy and Sell Stock III

**Difficulty:** Hard
**Tags:** dynamic-programming, array, state-machine

## Problem

Given an array representing daily stock prices, determine the maximum profit achievable by completing at most two buy-sell transactions. Transactions cannot overlap—you must sell a stock before purchasing another. The array can contain up to 100,000 elements with prices ranging from 0 to 100,000.

## Approach

The solution uses a three-dimensional dynamic programming table where `dp[x][holding][transactions]` represents the maximum profit at day `x`, with `holding` indicating whether we currently hold stock (1) or not (0), and `transactions` tracking how many transactions remain (0, 1, or 2). The DP is computed backwards from the last day to the first.

For each state, the code considers two choices: doing nothing (carrying forward the previous state) or taking an action. When not holding stock, the action is to buy (transitioning to holding state and decrementing available transactions). When holding stock, the action is to sell (transitioning to not-holding and moving to the next transaction count).

The base case initializes the last day: if holding stock on the last day with transactions remaining, the value equals the stock price (immediate sell); otherwise it's 0. The recurrence relations use `max` to choose between maintaining the current state or executing a transaction. The final answer is `dp[0][0][0]`, representing maximum profit starting from day 0 with no stock held and 0 transactions completed (2 remaining).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-30 09:20 UTC
- Runtime: 441 ms
- Memory: 210.1 MB
- Language: C++
