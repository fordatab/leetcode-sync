# Biggest Single Number

**Difficulty:** Easy
**Tags:** sql, group-by, aggregation, subquery

## Problem

Given a table of integers where values may repeat, find the largest number that appears exactly once in the table. If no number appears exactly once, return null. The table has no primary key and can contain duplicate values.

## Approach

The solution uses a nested query approach. The inner subquery groups all numbers by their value and filters using a HAVING clause to keep only those numbers that appear exactly once (COUNT = 1). This produces a result set containing all single-occurrence numbers. The outer query then applies the MAX aggregate function to find the largest value among these single numbers. If the inner query returns no rows (meaning no single numbers exist), MAX returns null automatically, satisfying the requirement to return null when there are no single numbers.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-08 05:47 UTC
- Runtime: 364 ms
- Memory: 0B
- Language: MySQL
