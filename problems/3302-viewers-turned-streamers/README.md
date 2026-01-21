# Viewers Turned Streamers

**Difficulty:** Hard
**Tags:** window-function, cte, join, aggregation, filtering

## Problem

Given a table of user sessions with start/end times and session types (Viewer or Streamer), find how many streaming sessions each user has, but only include users whose very first session (chronologically by start time) was as a Viewer. Return the user ID and their count of streaming sessions, ordered by count descending, then by user ID descending.

## Approach

The solution uses a CTE to identify each user's initial session type. It applies the `FIRST_VALUE` window function partitioned by user and ordered by session start time to capture whether each user's first session was 'Viewer' or 'Streamer'. The main query then joins this CTE back to the original sessions table and filters for users whose initial type was 'Viewer' and whose current session type is 'Streamer'. It groups by user ID to count the streaming sessions, excluding users who either started as streamers or never streamed after their initial viewer session. The result is sorted by streaming session count and user ID, both in descending order.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-21 11:41 UTC
- Runtime: 326 ms
- Memory: 0B
- Language: MySQL
