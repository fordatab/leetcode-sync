# Second Highest Salary

**Difficulty:** Medium
**Tags:** sql, sorting, subquery, limit-offset

## Problem

Given a table of employee salaries, find the second highest unique salary value. If fewer than two distinct salary values exist in the table, return null instead. The result must be returned with a specific column name.

## Approach

The solution uses a nested subquery approach. The inner query selects distinct salary values, orders them in descending order, and uses `LIMIT 1 OFFSET 1` to skip the highest salary and retrieve the second highest. The `DISTINCT` keyword ensures duplicate salary values are treated as one. The outer query wraps this result to handle the case where no second highest exists—if the inner query returns nothing (because there are fewer than two distinct salaries), the outer `SELECT` automatically produces null. This wrapping also allows aliasing the result column as `SecondHighestSalary` to meet the output format requirement.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:59 UTC
- Runtime: 215 ms
- Memory: 0B
- Language: MySQL
