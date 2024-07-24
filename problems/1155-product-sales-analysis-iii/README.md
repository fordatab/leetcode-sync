# Product Sales Analysis III

**Difficulty:** Medium
**Tags:** sql, subquery, aggregation, group-by, filtering

## Problem

Given a sales table where each row records a product sale in a particular year with quantity and price information, find all sales records that occurred in the earliest year each product was sold. For each product, identify its first appearance year in the table and return all sales entries for that product in that specific year, including the product ID, first year, quantity, and price.

## Approach

The solution uses a subquery with a correlated filter to identify first-year sales. The inner query groups sales by product_id and computes the minimum year for each product using MIN(year). The outer query then filters the Sales table to only include rows where the (product_id, year) pair matches one of the (product_id, MIN(year)) pairs from the subquery. This effectively selects all sales records that occurred in each product's earliest year. The year column is aliased as first_year in the final output.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:57 UTC
- Runtime: 1142 ms
- Memory: 0B
- Language: MySQL
