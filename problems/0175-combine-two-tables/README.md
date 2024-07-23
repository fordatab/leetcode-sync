# Combine Two Tables

**Difficulty:** Easy
**Tags:** sql, left-join, database

## Problem

Given two tables Person and Address, retrieve the first name, last name, city, and state for each person. The Person table contains personId (primary key), firstName, and lastName. The Address table contains addressId (primary key), personId (foreign key), city, and state. If a person has no corresponding address record, return null for city and state fields.

## Approach

The solution uses a LEFT JOIN to combine the Person and Address tables on the personId field. By using LEFT JOIN (instead of INNER JOIN), all rows from the Person table are preserved in the result, even when there's no matching personId in the Address table. When no match exists, the city and state columns automatically return NULL values. The query selects the required columns (firstName, lastName from Person; city, state from Address) and aliases both tables as P and A for brevity.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 22:37 UTC
- Runtime: 567 ms
- Memory: 0B
- Language: MySQL
