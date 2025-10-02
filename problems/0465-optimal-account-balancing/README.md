# Optimal Account Balancing

**Difficulty:** Hard
**Tags:** backtracking, hash-table, recursion, greedy, combinatorial-optimization

## Problem

Given a list of monetary transactions between people identified by IDs, where each transaction specifies a sender, receiver, and amount, find the minimum number of settling transactions needed to balance all debts. Each person ends up with a net balance (positive if owed money, negative if owing money), and the goal is to find the fewest transactions that zero out all balances. The input is limited to at most 8 transactions and person IDs under 12.

## Approach

The solution first computes each person's net balance by processing all transactions: subtracting amounts from senders and adding to receivers. It then collects all non-zero balances into a debt vector (using a fixed-size array of 13 for simplicity).

The core algorithm uses backtracking to explore different ways of settling debts. Starting from index 0, it tries to match each person who owes money (negative balance) with every person who is owed money (positive balance) that comes later in the array. The key insight checked by `debt[i] * debt[idx] < 0` ensures the two balances have opposite signs.

When a pair is found, it simulates a transaction by adding the current person's debt to the other person's balance, recursively explores that path counting one more transaction, then backtracks by undoing the change. If a person has zero balance, it's skipped. The recursion tracks the minimum transaction count across all possible settlement orderings.

## Complexity

- **Time:** O(n! * n)
- **Space:** O(n)

## Stats

- Submitted: 2025-10-02 08:20 UTC
- Runtime: 7 ms
- Memory: 9.3 MB
- Language: C++
