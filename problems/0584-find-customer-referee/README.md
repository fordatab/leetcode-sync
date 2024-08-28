# Find Customer Referee

**Difficulty:** Easy
**Tags:** sql, database, null-handling, filtering

## Problem

Given a Customer table with columns id, name, and referee_id, find the names of customers who were either not referred by anyone (referee_id is NULL) or were referred by someone other than the customer with id 2. The referee_id can be NULL, indicating no referrer, or contain an integer representing another customer's id.

## Approach

The solution uses a `SELECT` query with a `WHERE` clause that filters customers based on their `referee_id`. The key insight is handling NULL values correctly: the `COALESCE` function converts NULL `referee_id` values to 0 before comparison. This ensures that customers with no referrer (NULL) are included in the results, since `COALESCE(NULL, 0)` returns 0, which is not equal to 2. Customers with a non-NULL `referee_id` are compared directly, including those referred by customer 2 (who are excluded) and those referred by any other customer (who are included).

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-28 07:55 UTC
- Runtime: 388 ms
- Memory: 0B
- Language: MySQL
