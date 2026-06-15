# Queries Quality and Percentage

**Difficulty:** Easy
**Tags:** sql, aggregation, group-by, conditional-logic

## Problem

Given a table of database queries with their name, position (1-500), and rating (1-5), calculate two metrics for each query name: (1) quality, defined as the average of rating/position ratios across all instances of that query, and (2) poor query percentage, defined as the percentage of instances where the rating is less than 3. Both metrics should be rounded to two decimal places.

## Approach

The solution uses SQL aggregation with GROUP BY to compute metrics per query name.

- Groups all rows by `query_name` to calculate metrics separately for each unique query
- Computes quality using `AVG(rating/position)` which automatically calculates the mean of the ratio across all rows in each group
- Calculates poor query percentage using a conditional sum: `SUM(CASE WHEN rating<3 THEN 1 ELSE 0 END)` counts rows with rating < 3, divides by total count, and multiplies by 100 to get percentage
- Applies `ROUND(..., 2)` to both computed columns to format results to two decimal places as required

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2026-06-15 03:25 UTC
- Runtime: 373 ms
- Memory: 0B
- Language: MySQL
