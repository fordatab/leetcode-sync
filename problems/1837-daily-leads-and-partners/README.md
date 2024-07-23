# Daily Leads and Partners

**Difficulty:** Easy
**Tags:** sql, group-by, aggregation, distinct-count

## Problem

Given a table of daily sales records containing date, product make name, lead ID, and partner ID (with possible duplicates), count the number of distinct leads and distinct partners for each combination of date and make name. The result should include all unique date-make pairs with their respective counts of unique leads and partners.

## Approach

The solution uses SQL aggregation with the `GROUP BY` clause to partition rows by date and make name. For each partition, it applies `COUNT(DISTINCT)` to both the lead_id and partner_id columns to count unique values. The grouping is done using positional notation (1, 2) which refers to the first and second columns in the SELECT clause (date_id and make_name). The result includes four columns: the grouping keys (date_id, make_name) and the two computed aggregates (unique_leads, unique_partners).

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 08:54 UTC
- Runtime: 799 ms
- Memory: 0B
- Language: MySQL
