# Project Employees I

**Difficulty:** Easy
**Tags:** sql, join, aggregation, grouping

## Problem

Given two tables — Project (linking projects to employees) and Employee (containing employee details including experience years) — calculate the average experience years of all employees assigned to each project, rounded to two decimal places. The result should include one row per project showing its ID and the computed average.

## Approach

The solution performs a LEFT JOIN between the Project and Employee tables on the employee_id column to combine project assignments with employee experience data. It then groups the results by project_id and applies the AVG aggregate function to calculate the mean experience years for each project's employees. The ROUND function formats the average to exactly two decimal places as required by the problem specification.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-08 05:48 UTC
- Runtime: 705 ms
- Memory: 0B
- Language: MySQL
