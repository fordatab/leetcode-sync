# Game Play Analysis IV

**Difficulty:** Medium
**Tags:** sql, subquery, date-manipulation, aggregation

## Problem

Given a table of player activity records with player ID, device ID, event date, and games played, calculate the fraction of players who logged in on the consecutive day immediately after their first login. The result should be rounded to two decimal places and represents the retention rate of players returning the day after their initial session.

## Approach

The solution uses a nested subquery approach to identify returning players. First, it finds each player's first login date by grouping all activity records by player_id and selecting the MIN(event_date). Then, it checks which activity records have an event_date that is exactly one day after a first login date by using DATE_SUB to shift each event_date back one day and checking if that (player_id, shifted_date) pair exists in the set of first logins. The main query counts the distinct player_ids that satisfy this condition (players who returned the next day) and divides by a subquery that counts all distinct players in the table. Finally, ROUND(..., 2) formats the result to two decimal places.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 05:33 UTC
- Runtime: 1043 ms
- Memory: 0B
- Language: MySQL
