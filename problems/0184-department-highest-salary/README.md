# Department Highest Salary

**Difficulty:** Medium
**Tags:** database, sql, correlated-subquery, join, aggregation

## Problem

Given two tables, Employee and Department, find all employees who earn the maximum salary within their respective department. The Employee table contains employee details including salary and department ID, while the Department table maps department IDs to names. Multiple employees can share the highest salary in a department, and all such employees should be included in the result.

## Approach

The solution uses a cross join between Department and Employee tables, filtered by matching department IDs. For each employee, it checks if their salary equals the maximum salary in their department using a correlated subquery. The subquery `(Select max(Salary) from Employee e2 where e2.DepartmentId=dep.Id)` calculates the highest salary for each department on the fly. When an employee's salary matches this maximum, they are included in the result set with their department name, employee name, and salary. This approach naturally handles cases where multiple employees share the top salary in a department, as all matching records pass the equality condition.

## Complexity

- **Time:** O(n * m * n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-24 04:52 UTC
- Runtime: 808 ms
- Memory: 0B
- Language: MySQL
