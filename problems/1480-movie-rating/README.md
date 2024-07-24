# Movie Rating

**Difficulty:** Medium
**Tags:** database, sql, join, aggregation, union

## Problem

Given three tables (Movies, Users, and MovieRating), find two specific results: first, identify the user who has rated the most movies, breaking ties by choosing the lexicographically smallest name; second, find the movie with the highest average rating specifically in February 2020, again breaking ties lexicographically. Both results should be returned in a single column called 'results'.

## Approach

The solution uses two separate subqueries combined with UNION ALL to produce the two required results:

**First subquery (most active user):** Joins the MovieRating and Users tables on user_id, groups by user name, and counts the number of ratings per user. It orders by count descending (to get the most active user first) and by name ascending (for lexicographic tiebreaking), then limits to one result.

**Second subquery (best movie in February 2020):** Joins MovieRating and Movies tables on movie_id, filters for ratings created in February 2020 using EXTRACT(YEAR_MONTH FROM created_at) = 202002, groups by movie title, and computes the average rating. It orders by average rating descending and by title ascending (for lexicographic tiebreaking), then limits to one result.

The UNION ALL combines both single-row results into a two-row output with a single 'results' column.

## Complexity

- **Time:** O(n log n + m log m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-07-24 08:59 UTC
- Runtime: 1030 ms
- Memory: 0B
- Language: MySQL
