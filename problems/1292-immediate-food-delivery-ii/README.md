# Immediate Food Delivery II

**Difficulty:** Medium
**Tags:** database, sql, aggregation, subquery, filtering

## Problem

Given a table of food delivery orders with order dates and preferred delivery dates, determine the percentage of customers whose first order was immediate (where the order date equals the preferred delivery date). Each customer has exactly one first order, defined as their earliest order by date. The result should be rounded to two decimal places.

## Approach

The solution uses a two-step filtering approach. First, it identifies each customer's first order using a subquery that groups by customer_id and finds the minimum order_date for each. This subquery returns pairs of (customer_id, earliest_order_date). The main query then filters the Delivery table to only include rows where the (customer_id, order_date) combination matches one of these first-order pairs.

Once filtered to first orders only, the solution calculates the percentage of immediate orders by comparing order_date with customer_pref_delivery_date. The boolean comparison `order_date = customer_pref_delivery_date` evaluates to 1 for immediate orders and 0 for scheduled orders. Taking the average of these binary values gives the proportion of immediate orders, which is then multiplied by 100 and rounded to 2 decimal places to get the final percentage.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-24 09:00 UTC
- Runtime: 554 ms
- Memory: 0B
- Language: MySQL
