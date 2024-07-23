# Invalid Tweets

**Difficulty:** Easy
**Tags:** sql, string, filtering

## Problem

Given a table of tweets with IDs and content, identify which tweets are invalid. A tweet is considered invalid if its content exceeds 15 characters in length. Return the tweet IDs of all invalid tweets in any order.

## Approach

The solution uses a simple SQL SELECT statement with a WHERE clause to filter tweets based on their content length. It employs the `CHAR_LENGTH()` function to count the number of characters in each tweet's content column and compares this count against the threshold of 15. Only tweets where the character count is strictly greater than 15 are included in the result set, returning just their `tweet_id` values.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 08:55 UTC
- Runtime: 651 ms
- Memory: 0B
- Language: MySQL
