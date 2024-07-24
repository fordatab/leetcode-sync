# Confirmation Rate

**Difficulty:** Medium
**Tags:** database, sql, join, aggregation, left-join

## Problem

Given two tables — one tracking user signups and another tracking confirmation message requests with their outcomes (either 'confirmed' or 'timeout') — calculate each user's confirmation rate as the ratio of confirmed messages to total confirmation requests, rounded to two decimal places. Users who made no confirmation requests should have a rate of 0.00.

## Approach

The solution performs a LEFT JOIN between the Signups and Confirmations tables on user_id to ensure all users appear in the result, even those with no confirmation requests. For each user, it converts the action column to binary values (1 for 'confirmed', 0 for anything else including NULL) using the IF function, then calculates the average of these binary values, which naturally produces the confirmation rate. The ROUND function formats the result to two decimal places. Finally, GROUP BY user_id aggregates the results per user.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:58 UTC
- Runtime: 669 ms
- Memory: 0B
- Language: MySQL
