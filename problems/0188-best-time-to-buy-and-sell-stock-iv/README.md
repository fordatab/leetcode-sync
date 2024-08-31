# Best Time to Buy and Sell Stock IV

**Difficulty:** Hard
**Tags:** dynamic-programming, array, state-machine

## Problem

Given an array of stock prices over consecutive days and a maximum transaction limit k, determine the highest profit achievable by buying and selling the stock. You can complete at most k buy-sell pairs, and you must sell before buying again (no overlapping transactions). Each transaction consists of one buy followed by one sell.

## Approach

This solution uses three-dimensional dynamic programming where `dp[i][holding][transactions_left]` represents the maximum profit from day `i` onward. The `holding` dimension (0 or 1) indicates whether we currently own stock, and `transactions_left` tracks how many transactions remain available.

The state transitions work backwards from the last day:
- If not holding stock (`holding=0`), we can either skip the day or buy stock, transitioning to the holding state and consuming the current price
- If holding stock (`holding=1`), we can either skip the day or sell, transitioning to not-holding and gaining the current price while decrementing transactions remaining

The base case initializes the last day with appropriate values: if holding stock on the last day, the best action is to sell immediately at `prices[n-1]`. The algorithm iterates backward through days and forward through transaction counts, building up optimal decisions. The answer is `dp[0][0][0]`, representing maximum profit starting from day 0 with no stock held and k transactions available.

## Complexity

- **Time:** O(n * k)
- **Space:** O(n * k)

## Stats

- Submitted: 2024-08-31 00:58 UTC
- Runtime: 4 ms
- Memory: 16.7 MB
- Language: C++
