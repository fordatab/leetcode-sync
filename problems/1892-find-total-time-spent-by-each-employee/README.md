# Find Total Time Spent by Each Employee

**Difficulty:** Easy
**Tags:** sql, aggregation, group-by, database

## Problem

Given a table tracking employee office entries and exits with timestamps in minutes, calculate the total time each employee spent in the office on each day. Employees can have multiple entry-exit pairs on the same day, and the result should aggregate these intervals per employee per day.

## Approach

The solution uses SQL aggregation with GROUP BY to combine multiple office visits per employee per day. For each (event_day, emp_id) combination, it calculates the total time by summing all out_time values and subtracting the sum of all in_time values. This works because summing differences equals the difference of sums: Σ(out - in) = Σ(out) - Σ(in). The query groups by both event_day and emp_id to produce one row per employee per day, and aliases event_day as 'day' in the output to match the expected column name.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 08:54 UTC
- Runtime: 547 ms
- Memory: 0B
- Language: MySQL
