# Product Price at a Given Date

**Difficulty:** Medium
**Tags:** database, sql, union, subquery, aggregation, date-filtering

## Problem

Given a table tracking product price changes over time, find the effective price of each product on August 16, 2019. Products start at a default price of 10, and each row records when a product's price changed to a new value. For products with no price changes on or before the target date, return the default price of 10; otherwise, return the most recent price change that occurred on or before that date.

## Approach

The solution uses a UNION of two queries to handle two distinct cases:

1. **Products with no changes by the target date**: The first query selects products whose IDs do not appear in any price change record dated on or before 2019-08-16, assigning them the default price of 10.

2. **Products with at least one change by the target date**: The second query finds the most recent price change for each product on or before 2019-08-16. It uses a subquery to group products by ID and select the maximum (most recent) change_date that is <= 2019-08-16, then filters the main table using this (product_id, change_date) pair to retrieve the corresponding new_price.

The UNION combines both result sets, producing one row per product with its effective price on the target date. The DISTINCT in the first query ensures no duplicate rows for products without changes.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:59 UTC
- Runtime: 600 ms
- Memory: 0B
- Language: MySQL
