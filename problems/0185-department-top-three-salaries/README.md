# Department Top Three Salaries

**Difficulty:** Hard
**Tags:** sql, window-function, dense-rank, join, partitioning

## Problem

Given two tables, Employee and Department, find all employees whose salaries rank in the top three unique salary values within their respective departments. Multiple employees can share the same salary, and departments with fewer than three unique salaries should include all employees. The output should list the department name, employee name, and salary for each qualifying employee.

## Approach

The solution uses a window function approach with a subquery. First, it joins the Employee and Department tables to associate each employee with their department name. Then it applies `DENSE_RANK()` partitioned by department name and ordered by salary in descending order. `DENSE_RANK()` is crucial here because it assigns the same rank to employees with identical salaries without skipping subsequent ranks (unlike `RANK()`), ensuring that if two employees earn the second-highest salary, the next distinct salary still receives rank 3. Finally, the outer query filters for rows where the dense rank is 3 or less, effectively selecting employees whose salaries fall within the top three unique salary tiers in their department.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-24 04:52 UTC
- Runtime: 835 ms
- Memory: 0B
- Language: MySQL
