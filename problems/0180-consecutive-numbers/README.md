# Consecutive Numbers

**Difficulty:** Medium
**Tags:** sql, database, self-join, consecutive-sequence

## Problem

Given a table with auto-incrementing IDs and numeric values, identify all distinct numbers that appear in at least three consecutive rows (based on sequential ID values). The table has sequential IDs starting from 1, and the task is to find numbers where the same value appears at ID positions i, i+1, and i+2.

## Approach

The solution uses a self-join approach by checking if the same number appears at consecutive ID positions. For each row with ID `i` and value `Num`, it verifies whether:

- A row exists with ID `i+1` and the same `Num` value
- A row exists with ID `i+2` and the same `Num` value

This is accomplished using subquery membership tests with the `IN` operator, checking tuples of (Id+1, Num) and (Id+2, Num) against all rows in the table. The `DISTINCT` keyword ensures each qualifying number appears only once in the result, even if it has multiple consecutive triplets.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-24 04:51 UTC
- Runtime: 733 ms
- Memory: 0B
- Language: MySQL
