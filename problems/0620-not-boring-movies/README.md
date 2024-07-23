# Not Boring Movies

**Difficulty:** Easy
**Tags:** sql, filtering, sorting

## Problem

Given a Cinema table with columns id, movie, description, and rating, select all movies that have an odd-numbered id and a description that is not equal to 'boring'. The results must be sorted by rating in descending order, with ratings being floats in the range [0, 10] with two decimal places.

## Approach

The solution uses a straightforward SQL SELECT query with filtering and sorting. It applies two conditions in the WHERE clause: `MOD(id, 2) = 1` to filter for odd-numbered IDs (using the modulo operator to check if the remainder when divided by 2 equals 1), and `description <> 'boring'` to exclude movies with a boring description. The results are then ordered by the rating column in descending order using `ORDER BY rating DESC`, ensuring higher-rated movies appear first in the output.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 22:38 UTC
- Runtime: 232 ms
- Memory: 0B
- Language: MySQL
