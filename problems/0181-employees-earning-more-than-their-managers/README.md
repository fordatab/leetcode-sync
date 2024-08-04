# Employees Earning More Than Their Managers

**Difficulty:** Easy
**Tags:** database, self-join, sql

## Problem

Given a table of employees where each row contains an employee's ID, name, salary, and their manager's ID, identify all employees whose salary exceeds that of their direct manager. The manager information is represented by a managerId foreign key that references another employee's ID in the same table. Employees without managers have a null managerId.

## Approach

The solution performs a self-join on the Employee table, aliasing it as `e1` (managers) and `e2` (employees). By joining on the condition `e1.id = e2.managerId`, each employee row in `e2` is matched with their corresponding manager row in `e1`. The WHERE clause then filters for cases where the employee's salary (`e2.salary`) is greater than their manager's salary (`e1.salary`). This effectively pairs each employee with their manager and checks the salary comparison in a single query. The result returns only the names of employees who meet this condition, labeled as 'Employee' in the output.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-04 08:05 UTC
- Runtime: 313 ms
- Memory: 0B
- Language: MySQL
