# Reformat Department Table

**Difficulty:** Easy
**Tags:** sql, pivot, aggregation, case-expression, group-by

## Problem

Given a table with department IDs, monthly revenue values, and month names, pivot the data so each department appears in one row with separate columns for each month's revenue. The original table stores one row per department-month combination, and the output should have 13 columns: one for the department ID and twelve for each month's revenue (Jan_Revenue through Dec_Revenue).

## Approach

The solution uses SQL aggregation with conditional logic to pivot rows into columns. For each department ID, it groups all revenue entries together using `GROUP BY id`. Then, for each of the twelve months, it creates a separate column using a `CASE` expression wrapped in `SUM()`. Each `CASE` statement checks if the current row's month matches the target month (e.g., 'jan', 'feb', etc.) and returns the revenue value if true, otherwise returns null. The `SUM()` function then aggregates these values per department, effectively selecting the single revenue value for that month or null if no data exists. This produces one row per department with all twelve month columns populated appropriately.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 22:36 UTC
- Runtime: 605 ms
- Memory: 0B
- Language: MySQL
