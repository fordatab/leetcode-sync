# Best Time to Buy and Sell Stock with Cooldown

**Difficulty:** Medium
**Tags:** dynamic-programming, state-machine, array, bottom-up

## Problem

Given an array of daily stock prices, determine the maximum profit from buying and selling shares multiple times, where after each sale you must wait one day (cooldown) before buying again. You can only hold one share at a time, meaning you must sell before buying again. The array length ranges from 1 to 5000 elements, with prices between 0 and 1000.

## Approach

This solution uses dynamic programming with state tracking. It maintains a 2D DP table where `dp[i][0]` represents the maximum profit at day `i` when you don't currently hold stock, and `dp[i][1]` represents the maximum profit when you do hold stock.

The algorithm works backwards from the last day. For the last day, if you don't hold stock the profit is 0, and if you do hold stock you can sell it for `prices[n-1]`.

For each earlier day, there are two transitions:
- `dp[x][0]` (not holding): either stay not holding from the next day, or buy stock today (paying `-prices[x]`) and transition to the holding state tomorrow
- `dp[x][1]` (holding): either keep holding from the next day, or sell today (gaining `prices[x]`) and transition to the not-holding state two days later (`x+2`) to account for the mandatory cooldown

The answer is `dp[0][0]`, representing the maximum profit starting from day 0 without initially holding stock.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-25 07:15 UTC
- Runtime: 8 ms
- Memory: 14.5 MB
- Language: C++
