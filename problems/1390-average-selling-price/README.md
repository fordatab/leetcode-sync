# Average Selling Price

**Difficulty:** Easy
**Tags:** sql, join, aggregation, date-range

## Problem

Given two tables, Prices (with product prices for date ranges) and UnitsSold (with units sold on specific dates), compute the average selling price for each product. The average is the total revenue (units × price for each sale) divided by total units sold, rounded to 2 decimal places. Products with no sales should have an average price of 0.

## Approach

The solution uses a LEFT JOIN to match each sale in UnitsSold with its corresponding price from Prices based on the product_id and whether the purchase_date falls within the price's date range (BETWEEN start_date AND end_date). For each product, it calculates the weighted average by multiplying units sold by the applicable price, summing these products, and dividing by the total units sold. The IFNULL function handles products with no sales by returning 0 instead of NULL. The result is rounded to 2 decimal places using ROUND, and grouped by product_id to get one row per product.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-08 05:47 UTC
- Runtime: 851 ms
- Memory: 0B
- Language: MySQL
