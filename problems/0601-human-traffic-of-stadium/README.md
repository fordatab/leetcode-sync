# Human Traffic of Stadium

**Difficulty:** Hard
**Tags:** window-functions, sliding-window, pattern-matching, sql

## Problem

Given a table of stadium visits with sequential IDs, visit dates, and attendance counts, find all records that are part of a sequence of at least three consecutive IDs where each record in that sequence has attendance of 100 or more people. Return the matching records sorted by visit date in ascending order.

## Approach

The solution uses window functions to look ahead and behind each row in the dataset. For every row, it calculates `LEAD` (next 1 and 2 rows) and `LAG` (previous 1 and 2 rows) based on ID ordering to access the `people` count of neighboring records.

The WHERE clause then checks three distinct patterns to determine if the current row is part of a valid 3+ consecutive sequence:
1. Current row starts a sequence (current, next, next+1 all ≥ 100)
2. Current row is in the middle (previous, current, next all ≥ 100)
3. Current row ends a sequence (previous-1, previous, current all ≥ 100)

If any of these three conditions is true, the row belongs to at least one valid consecutive triplet and is included in the result. This approach captures all rows that participate in any qualifying sequence, even if that sequence is longer than three records.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 09:02 UTC
- Runtime: 299 ms
- Memory: 0B
- Language: MySQL
