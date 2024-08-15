# Lemonade Change

**Difficulty:** Easy
**Tags:** greedy, simulation, array

## Problem

Given a sequence of customer bills (each being $5, $10, or $20) at a lemonade stand where each lemonade costs $5, determine whether you can provide correct change to every customer in order, starting with no initial change. You must process customers sequentially and maintain enough bills to make change for each transaction.

## Approach

The solution uses a greedy approach tracking counts of $5 and $10 bills in hand. For each customer:

- **$5 bill**: Simply increment the count of $5 bills (no change needed).
- **$10 bill**: Requires giving back one $5 bill as change. Decrement the $5 count and increment the $10 count. If no $5 bills are available, return false.
- **$20 bill**: Requires $15 in change. The code prioritizes giving one $10 and one $5 (preserving more flexible $5 bills) by first checking if a $10 is available. If not, it attempts to give three $5 bills. If neither option is possible due to insufficient bills, return false.

The algorithm processes bills sequentially and immediately returns false when change cannot be made, otherwise returns true after processing all customers.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-15 00:41 UTC
- Runtime: 112 ms
- Memory: 86 MB
- Language: C++
