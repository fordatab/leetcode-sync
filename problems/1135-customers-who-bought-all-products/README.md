# Customers Who Bought All Products

**Difficulty:** Medium
**Tags:** aggregation, group-by, subquery, sql, set-operations

## Problem

Given two tables - Customer (containing customer purchases with possible duplicates) and Product (containing all available products) - find all customer IDs who have purchased every single product that exists in the Product table. The Customer table has foreign key references to Product via product_key, and the goal is to identify customers whose distinct product purchases cover the complete product catalog.

## Approach

The solution uses aggregation with a subquery comparison. First, it groups all customer records by customer_id and counts the number of distinct products each customer has purchased using `COUNT(DISTINCT product_key)`. Then, it compares this count against the total number of products in the Product table via a subquery `(SELECT COUNT(product_key) FROM Product)`. The HAVING clause filters to keep only those customers whose distinct product count equals the total product count, meaning they bought all products. The DISTINCT keyword in the count is crucial to handle duplicate purchase records in the Customer table.

## Complexity

- **Time:** O(n + m)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-24 08:56 UTC
- Runtime: 661 ms
- Memory: 0B
- Language: MySQL
