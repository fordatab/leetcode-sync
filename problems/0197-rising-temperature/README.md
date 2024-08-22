# Rising Temperature

**Difficulty:** Easy
**Tags:** sql, self-join, date-comparison, cross-join

## Problem

Given a Weather table with columns id, recordDate, and temperature, identify all records where the temperature is higher than the temperature recorded on the immediately preceding calendar day. Return the id values of these records in any order.

## Approach

The solution uses a self-join on the Weather table, creating two aliases (w1 and w2) to compare each row with all other rows. For each row in w1, it searches for a matching row in w2 where the date difference is exactly 1 day (using DATEDIFF to compute w1.recordDate - w2.recordDate). When such a pair is found and w1's temperature exceeds w2's temperature, w1.id is included in the result. This approach leverages SQL's ability to perform cross-table comparisons through the comma-separated FROM clause, which produces a Cartesian product filtered by the WHERE conditions.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 09:00 UTC
- Runtime: 471 ms
- Memory: 0B
- Language: MySQL
