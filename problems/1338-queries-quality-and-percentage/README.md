# Queries Quality and Percentage

**Difficulty:** Easy
**Tags:** sql, aggregation, group-by, conditional-aggregation

## Problem

Given a table of database queries with their name, position (1-500), and rating (1-5), compute two aggregated metrics per query name: the quality score (average of rating/position ratios) and the poor query percentage (percentage of queries with rating < 3). Both metrics must be rounded to two decimal places.

## Approach

The solution groups all rows by `query_name` and computes two aggregate metrics in a single pass. For quality, it calculates `rating/position` for each row and takes the average using `AVG()`. For poor query percentage, it uses a conditional `SUM(CASE...)` to count rows where `rating < 3`, divides by the total count of rows in each group, multiplies by 100 to get a percentage, and applies `ROUND(..., 2)` to both metrics to format the output to two decimal places.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2026-06-15 03:25 UTC
- Runtime: 373 ms
- Memory: 0B
- Language: MySQL
