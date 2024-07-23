# Article Views I

**Difficulty:** Easy
**Tags:** sql, filtering, distinct, sorting

## Problem

Given a table of article views where each row records an article, its author, a viewer, and the view date, find all authors who have viewed at least one of their own articles. The table may contain duplicate rows and has no primary key. Return the author IDs in ascending order without duplicates.

## Approach

The solution filters the Views table to find rows where the author_id equals the viewer_id, indicating that an author viewed their own article. It uses a WHERE clause for this equality check, then applies DISTINCT to eliminate duplicate author IDs (since an author may have viewed their own articles multiple times or viewed multiple articles they wrote). Finally, it orders the results by ID in ascending order and aliases the author_id column as 'id' for the output format.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2024-07-23 22:37 UTC
- Runtime: 414 ms
- Memory: 0B
- Language: MySQL
