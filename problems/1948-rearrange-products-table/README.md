# Rearrange Products Table

**Difficulty:** Easy
**Tags:** database, sql, unpivot, union

## Problem

Given a table with product IDs and prices across three stores (store1, store2, store3), transform it from a wide format to a long format. Each output row should contain a product ID, store name, and price. Null prices indicate a product isn't available at that store and should be excluded from the result.

## Approach

The solution uses a UNION-based unpivoting technique to transform the wide table format into a long format. It executes three separate SELECT queries, one for each store column. Each query selects the product_id, a literal string for the store name ('store1', 'store2', or 'store3'), and the corresponding price column. A WHERE clause filters out rows where the price is NULL for that particular store. The three result sets are combined using UNION, which automatically removes duplicates (though none exist in this case) and stacks the rows vertically to produce the final unpivoted table.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 08:55 UTC
- Runtime: 819 ms
- Memory: 0B
- Language: MySQL
