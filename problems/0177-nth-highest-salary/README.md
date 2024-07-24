# Nth Highest Salary

**Difficulty:** Medium
**Tags:** sql, sorting, offset-limit, stored-function

## Problem

Given an Employee table with id and salary columns, find the nth highest distinct salary value. The function must handle cases where there are fewer than n distinct salaries by returning null. Duplicate salary values should be treated as a single distinct value when ranking.

## Approach

The solution creates a MySQL stored function that accepts an integer N as input. It first decrements N by 1 to convert from 1-indexed to 0-indexed positioning (since OFFSET is 0-based). The query selects distinct salary values, orders them in descending order to get highest salaries first, then uses LIMIT 1 with OFFSET N to retrieve the salary at the Nth position. If fewer than N distinct salaries exist, the OFFSET will exceed the result set and MySQL automatically returns NULL. This approach relies on MySQL's behavior of returning NULL when OFFSET goes beyond available rows rather than explicitly checking the count of distinct salaries.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:59 UTC
- Runtime: 413 ms
- Memory: 0B
- Language: MySQL
