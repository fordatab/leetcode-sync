# Number of Unique Subjects Taught by Each Teacher

**Difficulty:** Easy
**Tags:** database, sql, group-by, aggregation, distinct

## Problem

Given a table where each row represents a teacher teaching a subject in a department, count how many distinct subjects each teacher teaches across all departments. The same teacher may teach the same subject in multiple departments, but that subject should only be counted once per teacher. Return each teacher's ID alongside their unique subject count.

## Approach

The solution uses SQL aggregation with the `GROUP BY` clause. First, it groups all rows by `teacher_id` to collect all teaching records for each teacher. Then, within each group, it applies `COUNT(DISTINCT subject_id)` to count only the unique subjects that teacher teaches, regardless of how many departments they teach that subject in. The `DISTINCT` keyword ensures that duplicate subject IDs for the same teacher are counted only once. The result is aliased as `cnt` to match the expected output format.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-22 11:22 UTC
- Runtime: 770 ms
- Memory: 0B
- Language: MySQL
