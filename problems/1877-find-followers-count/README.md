# Find Followers Count

**Difficulty:** Easy
**Tags:** database, sql, group-by, aggregation

## Problem

Given a table of user-follower relationships where each row represents one follower following one user, calculate how many followers each user has. The result should list each user_id that appears in the table along with their follower count, sorted by user_id in ascending order.

## Approach

The solution uses SQL aggregation to count followers per user. It groups all rows by `user_id`, which collects all follower relationships for each user together. The `COUNT(*)` function then counts how many rows (followers) exist in each group. Finally, the results are sorted by `user_id` in ascending order as required. This straightforward GROUP BY approach leverages the fact that each row in the input table represents exactly one follower relationship.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-25 05:03 UTC
- Runtime: 475 ms
- Memory: 0B
- Language: MySQL
