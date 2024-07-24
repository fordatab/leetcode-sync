# Managers with at Least 5 Direct Reports

**Difficulty:** Medium
**Tags:** database, sql, join, group-by, aggregation

## Problem

Given an Employee table with columns id, name, department, and managerId, find the names of all managers who have at least five employees reporting directly to them. The managerId column references the id of an employee's manager, or is null if the employee has no manager.

## Approach

The solution uses a self-join approach. First, it creates a subquery (E2) that groups employees by their managerId and counts the number of direct reports for each manager. The HAVING clause filters this to only include managers with 5 or more direct reports. Then, the outer query joins the original Employee table (E1) with this subquery on the condition that E1.id matches E2.managerId, effectively retrieving the names of managers who appear in the filtered subquery result.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:57 UTC
- Runtime: 308 ms
- Memory: 0B
- Language: MySQL
