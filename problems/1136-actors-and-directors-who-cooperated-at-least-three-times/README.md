# Actors and Directors Who Cooperated At Least Three Times

**Difficulty:** Easy
**Tags:** database, sql, grouping, aggregation

## Problem

Given a table of actor-director collaborations with timestamps, find all (actor_id, director_id) pairs where the same actor and director have worked together on at least three separate occasions. Each row represents one collaboration instance identified by a unique timestamp.

## Approach

The solution uses SQL aggregation to count collaborations per actor-director pair. It groups all rows by the combination of `actor_id` and `director_id`, then applies a `HAVING` clause to filter only those groups where the count of timestamps (representing individual collaborations) is at least 3. The `GROUP BY` clause naturally collapses multiple collaboration records into a single row per unique pair, and the count aggregation determines how many times each pair appears in the original table.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-08 05:47 UTC
- Runtime: 356 ms
- Memory: 0B
- Language: MySQL
