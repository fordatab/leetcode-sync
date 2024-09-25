# Primary Department for Each Employee

**Difficulty:** Easy
**Tags:** sql, database, subquery, aggregation, group-by

## Problem

Given a table of employee-department relationships where employees can belong to multiple departments, identify each employee's primary department. When an employee belongs to multiple departments, one is marked with a 'Y' flag as primary. However, employees belonging to only one department have their flag set to 'N', and that single department should be treated as their primary. The task is to return one department per employee following these rules.

## Approach

The solution uses a UNION-like approach through an OR condition. It selects rows where either:

1. The `primary_flag` is explicitly 'Y', capturing employees in multiple departments who have designated a primary one, or
2. The `employee_id` appears in a subquery that groups employees and filters for those with exactly one department (count = 1).

The subquery handles the edge case where single-department employees have 'N' flags but should still be included. By combining both conditions with OR, the query ensures all employees appear exactly once with their appropriate department—either their explicitly marked primary or their only department.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 05:01 UTC
- Runtime: 625 ms
- Memory: 0B
- Language: MySQL
