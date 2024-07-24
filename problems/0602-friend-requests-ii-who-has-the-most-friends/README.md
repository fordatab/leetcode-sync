# Friend Requests II: Who Has the Most Friends

**Difficulty:** Medium
**Tags:** sql, union, group-by, aggregation, common-table-expression

## Problem

Given a table of accepted friend requests with requester and accepter IDs, find the person who has the most friends and return their ID along with their friend count. Each accepted request represents a bidirectional friendship between the requester and accepter. The problem guarantees exactly one person has the maximum number of friends.

## Approach

The solution uses a CTE (Common Table Expression) to create a unified view of all user IDs involved in friendships. It combines `requester_id` and `accepter_id` columns using `UNION ALL`, treating each person's appearance in either column as one friendship connection. The main query then groups by user ID and counts occurrences to determine total friends per person. Finally, it sorts by friend count in descending order and uses `LIMIT 1` to return only the person with the most friends. Since each accepted request creates two entries in the base table (one for each participant), the count accurately reflects the total number of distinct friendships for each user.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:56 UTC
- Runtime: 313 ms
- Memory: 0B
- Language: MySQL
