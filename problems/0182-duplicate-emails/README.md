# Duplicate Emails

**Difficulty:** Easy
**Tags:** sql, group-by, aggregation, filtering

## Problem

Given a Person table with id and email columns where id is the primary key, identify all email addresses that appear more than once in the table. The result should list each duplicate email exactly once, in any order.

## Approach

The solution uses SQL aggregation to find duplicate emails. It groups all rows by the email column, then applies a HAVING clause to filter groups where the count of emails exceeds 1. This effectively identifies emails that appear multiple times in the table. The GROUP BY consolidates identical emails into single groups, and COUNT(email) tallies how many times each email appears. Only groups with more than one occurrence pass the HAVING filter and are returned in the result set.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-13 03:42 UTC
- Runtime: 348 ms
- Memory: 0B
- Language: MySQL
