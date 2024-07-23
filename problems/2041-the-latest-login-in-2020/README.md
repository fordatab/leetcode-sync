# The Latest Login in 2020

**Difficulty:** Easy
**Tags:** database, sql, aggregation, filtering, grouping

## Problem

Given a table of user login records with user IDs and timestamps, find the most recent login timestamp for each user who logged in during the year 2020. Users without any 2020 logins should be excluded from the results. The output should contain each qualifying user_id paired with their latest 2020 login timestamp.

## Approach

The solution filters the Logins table to include only records from 2020 using the `YEAR()` function on the time_stamp column. It then groups the filtered results by user_id and applies the `MAX()` aggregate function to find the latest timestamp for each user. The WHERE clause ensures that only 2020 logins are considered, automatically excluding users who didn't log in during that year. The result columns are aliased as user_id and last_stamp to match the expected output format.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-23 22:36 UTC
- Runtime: 492 ms
- Memory: 0B
- Language: MySQL
