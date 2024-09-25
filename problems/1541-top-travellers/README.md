# Top Travellers

**Difficulty:** Easy
**Tags:** sql, join, aggregation, sorting

## Problem

Given two tables — Users (with id and name) and Rides (with id, user_id, and distance) — calculate the total distance traveled by each user. Users who have no rides should appear with a distance of zero. The results must be sorted first by total distance in descending order, and then by user name in ascending order for ties.

## Approach

The solution performs a **LEFT JOIN** between the Users and Rides tables, matching each user with their rides via the user_id foreign key. It uses `IFNULL(SUM(r.distance), 0)` to compute the total distance for each user, handling cases where a user has no rides (the sum would otherwise be NULL). The results are grouped by `user_id` to aggregate distances per user, then ordered first by `travelled_distance` descending and second by `name` ascending to satisfy the tie-breaking requirement.

## Complexity

- **Time:** O(n log n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-09-25 04:58 UTC
- Runtime: 775 ms
- Memory: 0B
- Language: MySQL
