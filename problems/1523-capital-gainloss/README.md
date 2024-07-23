# Capital Gain/Loss

**Difficulty:** Medium
**Tags:** sql, aggregation, group-by, case-statement

## Problem

Given a table of stock transactions with buy and sell operations, calculate the net capital gain or loss for each stock. Each row contains a stock name, operation type (Buy or Sell), operation day, and price. The problem guarantees that every buy has a corresponding future sell and vice versa. The result should group transactions by stock name and compute the total profit or loss across all buy-sell pairs.

## Approach

The solution uses a simple aggregation strategy that treats all buy operations as negative values and all sell operations as positive values. By applying a CASE statement to negate the price for 'Buy' operations while keeping 'Sell' prices positive, the SUM aggregation automatically calculates the net gain/loss: selling prices are added while purchase costs are subtracted. The GROUP BY clause groups all transactions by stock_name, ensuring each stock's complete trading history is summed together to produce a single capital gain/loss figure per stock.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 08:54 UTC
- Runtime: 515 ms
- Memory: 0B
- Language: MySQL
