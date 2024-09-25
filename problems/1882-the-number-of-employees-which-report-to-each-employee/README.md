# The Number of Employees Which Report to Each Employee

**Difficulty:** Easy
**Tags:** sql, join, self-join, aggregation, group-by

## Problem

Given a table of employees where each employee may have a manager (indicated by a reports_to field), identify all managers who have at least one direct report. For each manager, calculate the count of their direct reports and the average age of those reports rounded to the nearest integer. The results should be ordered by employee_id.

## Approach

The solution uses a self-join on the Employees table to connect employees with their managers. The table is joined twice: once as `emp` (representing employees) and once as `mgr` (representing managers). The join condition `emp.reports_to = mgr.employee_id` links each employee to their manager.

After the join, the query groups results by `employee_id` (the manager's ID). For each manager, it counts the number of direct reports using `COUNT(emp.employee_id)` and computes the average age of those reports using `AVG(emp.age)`, rounding the result with `ROUND()`.

The implicit filtering happens through the inner join itself: only managers who appear in the `reports_to` column of at least one other employee will have matching rows after the join, automatically excluding employees with no reports. Finally, results are sorted by `employee_id` in ascending order.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 05:02 UTC
- Runtime: 586 ms
- Memory: 0B
- Language: MySQL
