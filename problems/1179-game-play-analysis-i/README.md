# Game Play Analysis I

**Difficulty:** Easy
**Tags:** sql, group-by, aggregation, database

## Problem

Given a table tracking player activity across multiple dates, find the earliest date each player logged in. The Activity table contains player_id, device_id, event_date, and games_played columns, with (player_id, event_date) as the primary key. Each player may have multiple login records on different dates, and the goal is to identify their first login date.

## Approach

The solution uses a straightforward SQL aggregation approach. It groups all activity records by `player_id` to collect all login dates for each player together. Then it applies the `MIN()` aggregate function to the `event_date` column within each group, which finds the earliest date among all login dates for that player. The result is aliased as `first_login` to match the expected output format. This single-pass aggregation efficiently identifies the minimum date for each player without requiring window functions or subqueries.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 22:39 UTC
- Runtime: 940 ms
- Memory: 0B
- Language: MySQL
