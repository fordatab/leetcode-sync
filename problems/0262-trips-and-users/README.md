# Trips and Users

**Difficulty:** Hard
**Tags:** database, sql, aggregation, filtering, subquery

## Problem

Given two tables tracking taxi trips and users, calculate the daily cancellation rate for trips occurring between October 1-3, 2013. A trip is excluded from the calculation if either the client or driver is banned. The cancellation rate is the ratio of cancelled trips (by either party) to total valid trips for each day, rounded to two decimal places.

## Approach

The solution filters the Trips table to exclude any trip involving banned users by using NOT IN subqueries against the Users table—one for banned clients and one for banned drivers. It also filters by the date range using direct string comparison. After filtering to only valid trips (those with unbanned participants in the specified date range), the query groups results by request_at date. For each date, it calculates the cancellation rate using a CASE expression within SUM to count cancelled trips (where status is either 'cancelled_by_driver' or 'cancelled_by_client'), divides by the total count of trips for that day, and rounds to two decimal places using ROUND.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 09:03 UTC
- Runtime: 1500 ms
- Memory: 0B
- Language: MySQL
