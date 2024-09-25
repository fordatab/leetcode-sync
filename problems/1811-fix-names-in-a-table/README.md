# Fix Names in a Table

**Difficulty:** Easy
**Tags:** string-manipulation, sql, string-functions

## Problem

Given a database table containing user IDs and names where names may have inconsistent capitalization, transform each name so that only the first character is uppercase and all remaining characters are lowercase. The result should be sorted by user_id in ascending order.

## Approach

The solution uses string manipulation functions in MySQL to reformat each name. It extracts the first character using `SUBSTR(name, 1, 1)` and converts it to uppercase with `UPPER()`, then extracts the remainder of the string starting from position 2 using `SUBSTR(name, 2)` and converts it to lowercase with `LOWER()`. These two parts are concatenated together using `CONCAT()` to form the properly capitalized name. The query selects the user_id along with this reformatted name, aliased as 'name', and orders the results by user_id in ascending order.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 05:03 UTC
- Runtime: 571 ms
- Memory: 0B
- Language: MySQL
