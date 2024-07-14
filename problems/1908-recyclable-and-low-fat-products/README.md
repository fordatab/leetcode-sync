# Recyclable and Low Fat Products

**Difficulty:** Easy
**Tags:** database, sql, filtering

## Problem

Given a Products table with columns for product_id, low_fats (enum 'Y'/'N'), and recyclable (enum 'Y'/'N'), find all product IDs where both low_fats and recyclable are set to 'Y'. The result can be returned in any order.

## Approach

This solution uses a straightforward SQL SELECT query with a WHERE clause to filter the Products table. It applies two conditions joined by AND: low_fats must equal 'Y' and recyclable must equal 'Y'. Only rows meeting both criteria are returned. The result is ordered by product_id in ascending order (though ordering is not required by the problem). The query directly scans the table and applies the filter conditions to identify qualifying products.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:59 UTC
- Runtime: 418 ms
- Memory: 0B
- Language: MySQL
