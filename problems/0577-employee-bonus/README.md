# Employee Bonus

**Difficulty:** Easy
**Tags:** database, left-join, sql, null-handling

## Problem

Given two tables Employee and Bonus, find all employees who either received a bonus less than 1000 or did not receive any bonus at all. The Employee table contains employee information including empId and name, while the Bonus table contains empId and bonus amount as a foreign key relationship. Return the employee name and their bonus amount (which may be null).

## Approach

The solution uses a LEFT JOIN to combine the Employee and Bonus tables on empId. A LEFT JOIN ensures all employees are included in the result, even those without a matching bonus record (who will have NULL for bonus columns). The WHERE clause then filters to keep only rows where the bonus is less than 1000 or where the Bonus record is NULL (indicating no bonus was awarded). This approach handles both conditions: employees with small bonuses and employees with no bonus entry.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-23 22:37 UTC
- Runtime: 969 ms
- Memory: 0B
- Language: MySQL
