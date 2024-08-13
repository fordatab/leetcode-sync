# Customers Who Never Order

**Difficulty:** Easy
**Tags:** subquery, set-operation, sql, filtering

## Problem

Given two tables — Customers (with id and name columns) and Orders (with id and customerId as a foreign key) — identify all customers who have never placed an order. The result should list customer names with no particular ordering requirement.

## Approach

The solution uses a subquery with the `NOT IN` operator. First, it retrieves all distinct customer IDs that appear in the Orders table via `SELECT customerId FROM Orders`. Then, the outer query selects customer names from the Customers table where the customer's id is not present in that set of order-placing customer IDs. This effectively filters out any customer who has at least one order, leaving only those who never ordered anything.

## Complexity

- **Time:** O(n * m)
- **Space:** O(m)

## Stats

- Submitted: 2024-08-13 03:43 UTC
- Runtime: 520 ms
- Memory: 0B
- Language: MySQL
