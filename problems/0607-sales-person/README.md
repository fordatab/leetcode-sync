# Sales Person

**Difficulty:** Easy
**Tags:** database, sql, join, filtering, right-join

## Problem

Given three tables (SalesPerson, Company, and Orders), find all salespersons who have never made any sales to a company named 'RED'. The Orders table links salespersons to companies through foreign keys, and we need to identify salespersons who either have no orders at all or only have orders with companies other than 'RED'.

## Approach

The solution uses a RIGHT JOIN strategy to identify salespersons without RED company orders:

1. First, it performs an INNER JOIN between Orders and Company, filtering only for orders where the company name is 'RED'. This creates a subset of orders specifically related to the RED company.

2. Next, it performs a RIGHT JOIN from this filtered result to the SalesPerson table. The RIGHT JOIN ensures all salespersons appear in the result, even if they have no matching orders with RED.

3. Finally, it filters for rows where `o.sales_id IS NULL`, which identifies salespersons who don't appear in the RED-filtered orders. These NULL values indicate salespersons who either made no sales to RED or made no sales at all.

The query effectively inverts the problem: instead of finding who sold to RED and excluding them, it finds the RED sales and uses a RIGHT JOIN to identify everyone not in that set.

## Complexity

- **Time:** O(n + m + p)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-08 05:46 UTC
- Runtime: 1241 ms
- Memory: 0B
- Language: MySQL
