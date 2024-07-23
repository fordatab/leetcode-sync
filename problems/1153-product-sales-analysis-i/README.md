# Product Sales Analysis I

**Difficulty:** Easy
**Tags:** database, sql, join, left-join

## Problem

Given two tables—Sales containing sale transactions with product IDs, years, quantities, and prices, and Product mapping product IDs to product names—retrieve the product name, year, and price for each sale. The Sales table uses (sale_id, year) as a composite primary key and has a foreign key reference to Product via product_id. The output can be in any order.

## Approach

The solution performs a LEFT JOIN between the Sales and Product tables using product_id as the join key. For each row in Sales, it retrieves the corresponding product_name from Product and combines it with the year and price columns from Sales. The LEFT JOIN ensures all sales records are included even if a matching product doesn't exist (though the foreign key constraint suggests this shouldn't happen). The query simply selects the three required columns: product_name from the joined Product table, and year and price from the Sales table.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 09:00 UTC
- Runtime: 1860 ms
- Memory: 0B
- Language: MySQL
