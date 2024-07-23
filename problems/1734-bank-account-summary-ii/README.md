# Bank Account Summary II

**Difficulty:** Easy
**Tags:** database, sql, join, aggregation, group-by

## Problem

Given two tables, Users (with account numbers and names) and Transactions (with transaction records showing amounts that can be positive or negative), find all users whose total account balance exceeds 10,000. The balance is calculated by summing all transaction amounts for each account, starting from an initial balance of zero.

## Approach

The solution uses a straightforward SQL aggregation approach:

- Performs an inner join between the Users and Transactions tables on the account number to link each user with their transaction history
- Groups the results by account number to aggregate transactions per user
- Uses SUM() to calculate the total balance for each account by adding up all transaction amounts (both positive and negative)
- Filters the grouped results with a HAVING clause to retain only those accounts where the computed balance exceeds 10,000
- Selects the user's name and their calculated balance for the final output

## Complexity

- **Time:** O(n + m)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-23 08:55 UTC
- Runtime: 670 ms
- Memory: 0B
- Language: MySQL
