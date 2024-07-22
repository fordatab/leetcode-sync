# Richest Customer Wealth

**Difficulty:** Easy
**Tags:** array, matrix, simulation

## Problem

Given a 2D grid where each row represents a customer and each element in that row represents the amount of money in one of their bank accounts, find the maximum total wealth among all customers. Each customer's wealth is the sum of all values in their row. The grid has dimensions up to 50x50 with values ranging from 1 to 100.

## Approach

The solution uses a straightforward iteration approach with two nested loops. For each customer (outer loop iterating through rows), it calculates their total wealth by summing all their bank account values (inner loop iterating through columns). A running maximum tracks the highest wealth seen so far, which is updated after computing each customer's total. The algorithm maintains a temporary variable `t` to accumulate the current customer's wealth and a maximum variable `m` to store the overall maximum wealth across all customers.

## Complexity

- **Time:** O(m * n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-22 20:23 UTC
- Runtime: 7 ms
- Memory: 10.8 MB
- Language: C++
