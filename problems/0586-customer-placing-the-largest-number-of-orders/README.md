# Customer Placing the Largest Number of Orders

**Difficulty:** Easy
**Tags:** sql, group-by, aggregation, sorting

## Problem

Given a table of orders where each row contains an order number and customer number, find the customer who has placed the most orders. The problem guarantees that exactly one customer will have more orders than all others, so there are no ties to handle.

## Approach

The solution uses SQL aggregation to count orders per customer. It groups all rows by `customer_number`, which clusters orders belonging to the same customer together. The `COUNT(customer_number)` aggregate function tallies how many orders each customer has. The results are then sorted in descending order by this count, placing the customer with the most orders at the top. Finally, `LIMIT 1` extracts only the first row, which is the customer with the maximum order count.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-28 07:54 UTC
- Runtime: 521 ms
- Memory: 0B
- Language: MySQL
