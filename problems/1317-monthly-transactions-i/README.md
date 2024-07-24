# Monthly Transactions I

**Difficulty:** Medium
**Tags:** sql, aggregation, group-by, conditional-logic

## Problem

Given a table of financial transactions with country, state (approved/declined), amount, and date fields, aggregate the data by month and country. For each month-country combination, calculate the total number of transactions, the count of approved transactions, the sum of all transaction amounts, and the sum of only approved transaction amounts.

## Approach

The solution uses `DATE_FORMAT` to extract the year-month portion from the transaction date, creating a grouping key. It then groups all records by this month string and country using `GROUP BY`. For each group, it counts all transactions with `COUNT(id)`, sums all amounts with `SUM(amount)`, and uses conditional aggregation with `IF` statements to separately count and sum only the approved transactions. The `IF(state = 'approved', 1, 0)` pattern returns 1 for approved transactions and 0 otherwise, which when summed gives the count of approved records. Similarly, `IF(state = 'approved', amount, 0)` includes the amount only for approved transactions in the sum.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:58 UTC
- Runtime: 638 ms
- Memory: 0B
- Language: MySQL
