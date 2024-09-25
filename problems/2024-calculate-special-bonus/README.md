# Calculate Special Bonus

**Difficulty:** Easy
**Tags:** sql, conditional-logic, string-matching

## Problem

Given a table of employees with their IDs, names, and salaries, calculate a bonus for each employee. An employee receives a bonus equal to their full salary if their ID is odd and their name does not start with 'M'; otherwise, they receive no bonus. The result should be sorted by employee ID.

## Approach

The solution uses a single SQL SELECT statement with arithmetic multiplication to compute the bonus. It leverages the fact that boolean conditions in MySQL evaluate to 1 (true) or 0 (false). The bonus is calculated by multiplying the salary by `(employee_id % 2)`, which gives 1 for odd IDs and 0 for even IDs, and by `(name not like 'M%')`, which gives 1 if the name doesn't start with 'M' and 0 if it does. When multiplied together with the salary, this produces either the full salary (when both conditions are true) or 0 (when either condition is false). The results are then ordered by employee_id as required.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 04:57 UTC
- Runtime: 496 ms
- Memory: 0B
- Language: MySQL
