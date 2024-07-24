# Market Analysis I

**Difficulty:** Medium
**Tags:** sql, left-join, aggregation, date-filtering

## Problem

Given three tables (Users, Orders, and Items) from an online shopping platform, find each user's join date and count how many orders they placed as a buyer specifically in 2019. All users must appear in the result even if they made zero purchases in 2019.

## Approach

The solution uses a LEFT JOIN to preserve all users from the Users table while matching their orders from the Orders table. The join condition includes both the user-buyer relationship (`u.user_id = o.buyer_id`) and a year filter (`YEAR(order_date) = '2019'`) to limit matched orders to 2019 only. By placing the year filter in the JOIN condition rather than a WHERE clause, users with no 2019 orders still appear with NULL order dates. The query then groups by user_id and uses `COUNT(order_date)` wrapped in `IFNULL` to convert NULL counts to 0, ensuring users without 2019 orders display 0 instead of NULL. The Items table is unused since the problem only requires counting orders, not analyzing item details.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 08:57 UTC
- Runtime: 1371 ms
- Memory: 0B
- Language: MySQL
