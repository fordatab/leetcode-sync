# Swap Sex of Employees

**Difficulty:** Easy
**Tags:** sql, case-statement, update-query, conditional-logic

## Problem

Given a table with employee records containing a sex column with values 'm' or 'f', swap all occurrences of these two values in a single UPDATE statement. The constraint requires doing this without using SELECT statements or temporary tables, performing the swap operation atomically across all rows.

## Approach

The solution uses a single UPDATE statement with a CASE expression to conditionally swap the sex values. For each row, the CASE evaluates the current sex value: if it's 'm', it assigns 'f'; otherwise (when it's 'f'), it assigns 'm'. This approach elegantly handles the bidirectional swap in one pass, as the CASE expression evaluates against the original value before any updates are applied, ensuring that all 'm' values become 'f' and all 'f' values become 'm' simultaneously without interference.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 08:57 UTC
- Runtime: 268 ms
- Memory: 0B
- Language: MySQL
