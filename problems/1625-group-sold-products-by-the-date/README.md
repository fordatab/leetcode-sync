# Group Sold Products By The Date

**Difficulty:** Easy
**Tags:** sql, aggregation, group-by, string-manipulation

## Problem

Given a table of product sales with dates and product names (potentially with duplicates), group the data by date and for each date output the count of distinct products sold and a comma-separated list of those product names sorted alphabetically. The results should be ordered chronologically by sale date.

## Approach

The solution uses SQL aggregation to group rows by `sell_date`. For each date group, it calculates two values: `num_sold` using `COUNT(DISTINCT product)` to count unique products, and `products` using `GROUP_CONCAT(DISTINCT product ORDER BY product ASC SEPARATOR ',')` to create a comma-separated string of distinct product names in lexicographic order. The `DISTINCT` keyword in both aggregations eliminates duplicate product entries within each date. Finally, the results are sorted by `sell_date` in ascending order to produce chronologically ordered output.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 22:36 UTC
- Runtime: 480 ms
- Memory: 0B
- Language: MySQL
