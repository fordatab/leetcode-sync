# Employees Whose Manager Left the Company

**Difficulty:** Easy
**Tags:** sql, subquery, filtering, set-operations

## Problem

Given a table of employees with their salaries and manager IDs, find the IDs of employees who earn less than $30,000 and whose manager is no longer in the company (their manager's record has been deleted from the table, but the employee's manager_id field still references that missing manager). The result should be sorted by employee_id in ascending order.

## Approach

The solution uses a subquery with a `NOT IN` clause to identify employees whose managers have left. First, it filters employees earning less than $30,000 using a `WHERE` clause. Then, it checks whether each employee's `manager_id` exists in the set of all current `employee_id` values by selecting all employee IDs in a subquery. If the `manager_id` is not in this set, it means the manager has left the company. Finally, the results are sorted by `employee_id` in ascending order. This approach directly checks for the absence of the manager's record in the employees table, which indicates the manager has departed.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 04:57 UTC
- Runtime: 361 ms
- Memory: 0B
- Language: MySQL
