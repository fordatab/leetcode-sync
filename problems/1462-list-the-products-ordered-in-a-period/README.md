# List the Products Ordered in a Period

**Difficulty:** Easy
**Tags:** sql, join, aggregation, filtering, date-functions

## Problem

Given two tables—Products (with product_id, product_name, and product_category) and Orders (with product_id, order_date, and unit)—find the names of products that had a combined total of at least 100 units ordered during February 2020. Return each qualifying product's name along with its total units ordered in that month.

## Approach

The solution joins the Products and Orders tables on product_id to connect product names with their order records. It filters orders to only those from February 2020 using `YEAR()` and `MONTH()` functions on the order_date. The results are grouped by product_id, and for each product, the units from all February 2020 orders are summed. Finally, a `HAVING` clause filters out any products whose total units are less than 100, leaving only those that meet the threshold.

## Complexity

- **Time:** O(n + m)
- **Space:** O(k)

## Stats

- Submitted: 2024-09-08 05:48 UTC
- Runtime: 710 ms
- Memory: 0B
- Language: MySQL
