# Odd and Even Transactions

**Difficulty:** Medium
**Tags:** sql, aggregation, conditional-logic, group-by

## Problem

Given a table of transactions with amounts and dates, calculate the sum of transaction amounts separately for odd-valued and even-valued amounts on each date. For dates where no odd or even transactions exist, display 0 for that category. Results must be sorted by date in ascending order.

## Approach

The solution groups all transactions by their date using `GROUP BY transaction_date`. For each date group, it uses conditional aggregation with `SUM(CASE ...)` expressions to separate odd and even amounts. The first `CASE` statement checks if `amount % 2 != 0` (odd) and includes that amount in the sum, otherwise contributes 0. The second `CASE` statement does the inverse for even amounts (`amount % 2 = 0`). This approach naturally handles missing odd or even transactions by summing to 0 when no matching amounts exist. Finally, results are sorted by `transaction_date` in ascending order.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-24 00:40 UTC
- Runtime: 250 ms
- Memory: 0B
- Language: MySQL
