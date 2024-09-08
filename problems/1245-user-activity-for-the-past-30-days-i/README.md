# User Activity for the Past 30 Days I

**Difficulty:** Easy
**Tags:** sql, database, grouping, aggregation, date-filtering

## Problem

Given a table of user activities with dates and activity types, count the number of distinct active users for each day within a 30-day window ending on 2019-07-27 (inclusive). A user is considered active on a day if they performed at least one activity of any type on that day. The table may contain duplicate rows, and each session belongs to exactly one user.

## Approach

The solution filters the Activity table to include only records within the specified 30-day period (from 2019-06-28 to 2019-07-27 inclusive) using a WHERE clause with date comparisons. It then groups the filtered results by activity_date and counts the number of distinct user_id values for each date using COUNT(DISTINCT user_id). The activity_date is aliased as 'day' and the count is aliased as 'active_users' in the final result. This approach automatically excludes days with zero active users since only dates present in the filtered dataset are grouped.

## Complexity

- **Time:** O(n)
- **Space:** O(d)

## Stats

- Submitted: 2024-09-08 05:49 UTC
- Runtime: 524 ms
- Memory: 0B
- Language: MySQL
