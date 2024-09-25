# Customer Who Visited but Did Not Make Any Transactions

**Difficulty:** Easy
**Tags:** sql, left-join, grouping, aggregation

## Problem

Given two tables — one tracking customer visits to a mall and another tracking transactions made during those visits — find all customers who visited at least once without making any transaction. For each such customer, count how many times they visited without making a purchase. A visit is considered transaction-free if its visit_id does not appear in the Transactions table.

## Approach

The solution uses a LEFT JOIN between the Visits and Transactions tables on the visit_id column. This join preserves all rows from Visits while bringing in matching transaction data where it exists. For visits without any corresponding transactions, the transaction columns (including transaction_id) will be NULL. The WHERE clause filters to keep only these NULL cases, effectively identifying visits with no transactions. Finally, the results are grouped by customer_id and counted to determine how many transaction-free visits each customer made.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 04:59 UTC
- Runtime: 1184 ms
- Memory: 0B
- Language: MySQL
