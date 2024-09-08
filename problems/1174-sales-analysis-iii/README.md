# Sales Analysis III

**Difficulty:** Easy
**Tags:** sql, join, group-by, aggregation, date-filtering

## Problem

Given two tables, Product (with product details) and Sales (with transaction records), identify products that were sold exclusively within the first quarter of 2019 (January 1 to March 31, inclusive). A product qualifies only if all of its sales occurred within this date range; any sale outside this window disqualifies it.

## Approach

The solution joins the Sales and Product tables on product_id, then groups all sales records by product. For each product group, it uses aggregate functions MIN and MAX on sale_date to find the earliest and latest sale dates. The HAVING clause filters to keep only products where the earliest sale is on or after January 1, 2019, AND the latest sale is on or before March 31, 2019. This ensures that all sales for that product fall within the specified quarter, effectively excluding products with any sales outside the date range.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-08 05:49 UTC
- Runtime: 1219 ms
- Memory: 0B
- Language: MySQL
