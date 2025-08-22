# Simple Bank System

**Difficulty:** Medium
**Tags:** array, simulation, design

## Problem

Design a banking system that manages n accounts numbered 1 to n, each with an initial balance. The system must support three operations: transferring money between accounts, depositing money into an account, and withdrawing money from an account. Each operation should only execute if the account numbers are valid (between 1 and n) and if there are sufficient funds for withdrawals or transfers, returning true on success and false otherwise.

## Approach

The solution uses a straightforward array-based implementation. The constructor stores the balance array and the number of accounts. Account numbers are 1-indexed in the API but the internal array is 0-indexed, so all operations convert by subtracting 1 from the account number.

Each operation first validates that account numbers fall within the valid range [1, n]. For withdraw and transfer operations, it also checks that the source account has sufficient funds before proceeding. The transfer operation is implemented as a withdrawal from account1 followed by a deposit to account2. The deposit operation simply adds money without validation beyond checking the account number exists.

All three operations return true when successful and false when any validation fails, maintaining the invariant that invalid operations leave the state unchanged.

## Complexity

- **Time:** O(1)
- **Space:** O(n)

## Stats

- Submitted: 2025-08-22 03:57 UTC
- Runtime: 13 ms
- Memory: 123.8 MB
- Language: C++
