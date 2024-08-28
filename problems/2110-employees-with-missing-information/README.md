# Employees With Missing Information

**Difficulty:** Easy
**Tags:** database, sql, joins, union, set-operations

## Problem

Given two tables, Employees (with employee_id and name) and Salaries (with employee_id and salary), find all employee IDs that appear in one table but not the other, or equivalently, employees whose name or salary information is missing. Return the results sorted by employee_id in ascending order.

## Approach

The solution uses a FULL OUTER JOIN pattern implemented via UNION of LEFT and RIGHT JOINs. First, it performs a LEFT JOIN of Employees to Salaries to capture all employees and their matching salary records (or NULL if no salary exists). Then it performs a RIGHT JOIN to capture all salary records and their matching employee names (or NULL if no name exists). The UNION combines both result sets, eliminating duplicates for employees present in both tables. Finally, it filters for rows where either the name or salary is NULL, indicating missing information, and orders the results by employee_id.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-28 05:43 UTC
- Runtime: 623 ms
- Memory: 0B
- Language: MySQL
