# Investments in 2016

**Difficulty:** Medium
**Tags:** sql, subquery, filtering, aggregation, group-by

## Problem

Given an insurance table with policy details including 2015 and 2016 investment values and geographic coordinates, find the sum of 2016 investment values for policyholders who share their 2015 investment value with at least one other policyholder but have a unique geographic location (no other policyholder at the same latitude and longitude pair). The result should be rounded to two decimal places.

## Approach

The solution uses a filtering approach with two subqueries to identify qualifying records:

1. The first subquery identifies all `tiv_2015` values that appear more than once in the table by grouping on `tiv_2015` and filtering groups with `COUNT(*) > 1`.

2. The second subquery identifies unique location pairs by grouping on `(lat, lon)` and filtering groups with `COUNT(*) = 1`, ensuring no two policyholders share the same coordinates.

3. The main query filters the Insurance table to include only rows where `tiv_2015` matches the first condition (appears multiple times) AND the `(lat, lon)` pair matches the second condition (appears exactly once).

4. Finally, it sums the `tiv_2016` values of qualifying rows and rounds the result to two decimal places using `ROUND(SUM(tiv_2016), 2)`.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 05:33 UTC
- Runtime: 482 ms
- Memory: 0B
- Language: MySQL
