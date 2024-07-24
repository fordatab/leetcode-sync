# Count Salary Categories

**Difficulty:** Medium
**Tags:** sql, aggregation, union, conditional-counting

## Problem

Given a table of bank accounts with monthly income values, count how many accounts fall into each of three salary categories: Low Salary (income < $20,000), Average Salary (income between $20,000 and $50,000 inclusive), and High Salary (income > $50,000). The result must include all three categories even if some have zero accounts.

## Approach

The solution uses three separate SELECT statements combined with UNION to create one row for each salary category. Each SELECT statement:

- Returns a hardcoded category name as a string literal
- Uses a boolean expression within SUM() to count matching rows (in MySQL, TRUE evaluates to 1 and FALSE to 0, so summing boolean conditions counts the number of TRUE values)
- Scans the entire Accounts table to evaluate the condition for that category

The three UNION operations stack the results vertically, producing a three-row result set with all categories and their respective counts. This approach guarantees all three categories appear in the output regardless of whether any accounts exist in each range.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 08:56 UTC
- Runtime: 1673 ms
- Memory: 0B
- Language: MySQL
