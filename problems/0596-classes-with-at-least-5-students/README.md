# Classes With at Least 5 Students

**Difficulty:** Easy
**Tags:** sql, group-by, aggregation, filtering

## Problem

Given a table that records student enrollments in classes where each (student, class) pair is unique, identify all classes that have at least five students enrolled. The output should list the class names that meet this threshold in any order.

## Approach

The solution uses SQL aggregation to count enrollments per class. It groups all rows by the `class` column, then applies a HAVING clause to filter out groups with fewer than five students. The COUNT function tallies the number of student entries for each class, and only classes meeting or exceeding the threshold of 5 are returned in the result set.

## Complexity

- **Time:** O(n)
- **Space:** O(k)

## Stats

- Submitted: 2024-09-08 05:46 UTC
- Runtime: 256 ms
- Memory: 0B
- Language: MySQL
