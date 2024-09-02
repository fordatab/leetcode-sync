# Big Countries

**Difficulty:** Easy
**Tags:** sql, filtering, database

## Problem

Given a table of countries with their continent, area, population, and GDP, identify countries that qualify as 'big' by meeting at least one of two criteria: having an area of 3 million square kilometers or more, or having a population of 25 million or more. Return the name, population, and area of these countries in any order.

## Approach

The solution uses a straightforward SQL SELECT statement with a WHERE clause that filters rows based on the OR condition. It retrieves rows where either the area column is at least 3,000,000 or the population column is at least 25,000,000. The query directly projects the three required columns (name, population, area) without any joins, aggregations, or subqueries, making it a simple single-pass filter operation over the World table.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-02 06:23 UTC
- Runtime: 276 ms
- Memory: 0B
- Language: MySQL
