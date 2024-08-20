# Delete Duplicate Emails

**Difficulty:** Easy
**Tags:** database, self-join, sql

## Problem

Given a Person table with id and email columns, remove all rows where the email appears more than once, retaining only the row with the smallest id for each email. The solution must modify the table in place using a DELETE statement, and the final table should contain only unique emails paired with their minimum id values.

## Approach

The solution uses a self-join on the Person table (aliased as p1 and p2) where both instances are joined on matching email addresses. The DELETE operation targets rows from p1 where the email matches between p1 and p2, but p1's id is greater than p2's id. This effectively removes all duplicate emails except the one with the smallest id, since for any duplicate email, all rows with higher ids will match the condition when paired with the row having the lowest id for that email.

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-20 05:25 UTC
- Runtime: 796 ms
- Memory: 0B
- Language: MySQL
