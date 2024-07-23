# Replace Employee ID With The Unique Identifier

**Difficulty:** Easy
**Tags:** database, sql, join, left-join

## Problem

Given two tables, Employees (containing employee IDs and names) and EmployeeUNI (containing employee IDs and their corresponding unique identifiers), retrieve each employee's name along with their unique ID. If an employee doesn't have a corresponding entry in the EmployeeUNI table, display null for their unique_id. The result can be returned in any order.

## Approach

The solution uses a LEFT JOIN between the Employees and EmployeeUNI tables, joining on the id column. This ensures all employees from the Employees table appear in the result set. For employees who have a matching entry in EmployeeUNI, their unique_id is displayed; for those without a match, the LEFT JOIN naturally produces null values. The query selects the unique_id from EmployeeUNI and the name from Employees, aliasing both columns explicitly in the output.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-23 09:00 UTC
- Runtime: 1025 ms
- Memory: 0B
- Language: MySQL
