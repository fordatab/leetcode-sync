# Restaurant Growth

**Difficulty:** Medium
**Tags:** sql, window-functions, date-arithmetic, aggregation, correlated-subquery

## Problem

Given a table of customer transactions with dates and amounts, calculate a 7-day sliding window sum and average for each date starting from the 7th day onwards. Each date may have multiple transactions from different customers, and the window includes the current date plus the previous 6 days. The average must be rounded to two decimal places, and results should be ordered by date.

## Approach

The solution uses a correlated subquery approach with date arithmetic. For each distinct `visited_on` date that occurs at least 6 days after the first transaction date, it performs two identical subqueries: one to compute the sum of all amounts in the 7-day window (using `DATE_SUB` to find the window start) and another to compute the average by dividing that sum by 7 and rounding to 2 decimal places. The outer query filters dates using a subquery that adds 6 days to the minimum date in the table, ensuring only dates with a complete 7-day window are included. The `GROUP BY visited_on` ensures each date appears once in the output even if multiple customers visited that day.

## Complexity

- **Time:** O(n² * m)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 08:58 UTC
- Runtime: 344 ms
- Memory: 0B
- Language: MySQL
