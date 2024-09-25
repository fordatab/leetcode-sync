# Percentage of Users Attended a Contest

**Difficulty:** Easy
**Tags:** sql, aggregation, grouping, percentage-calculation

## Problem

Given two tables—Users (containing user IDs and names) and Register (tracking which users registered for which contests)—calculate the percentage of all users who registered for each contest. The percentage should be rounded to two decimal places, and results should be ordered by percentage descending, with ties broken by contest ID ascending.

## Approach

The solution groups registrations by contest ID and counts the distinct users per contest. For each contest, it calculates the percentage by dividing the user count by the total number of users (obtained via a subquery on the Users table) and multiplying by 100. The `ROUND` function ensures two-decimal precision. Finally, results are sorted first by percentage in descending order, then by contest ID in ascending order to handle ties.

- Groups the Register table by `contest_id`
- Counts distinct `user_id` values per group
- Uses a scalar subquery `(SELECT COUNT(user_id) FROM Users)` to get the total user count
- Multiplies the ratio by 100 and rounds to 2 decimals
- Orders by percentage descending, then contest_id ascending

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 05:00 UTC
- Runtime: 877 ms
- Memory: 0B
- Language: MySQL
