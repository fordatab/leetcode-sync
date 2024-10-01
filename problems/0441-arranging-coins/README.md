# Arranging Coins

**Difficulty:** Easy
**Tags:** math, simulation, iteration

## Problem

Given n coins, determine how many complete rows can be formed in a staircase where row i contains exactly i coins. The staircase is built from top to bottom, with row 1 having 1 coin, row 2 having 2 coins, and so on. Return the count of fully completed rows, with n constrained to values up to 2^31 - 1.

## Approach

The solution uses a greedy simulation approach that iteratively subtracts the cost of each row from the remaining coin count. Starting with `out = 1` (representing the current row number), it repeatedly subtracts `out` from `n` and increments `out` until there aren't enough coins left to complete another row (when `n` becomes non-positive).

After the loop exits, the code checks whether the last subtraction resulted in exactly zero remaining coins (meaning the last row was perfectly completed) or a negative value (meaning we ran out of coins partway through a row). If `n == 0`, we return `out - 1` because `out` was incremented one extra time. If `n < 0`, we return `out - 2` because we couldn't complete the row we just attempted, and `out` was incremented past it.

This is a straightforward iterative simulation that doesn't use the mathematical formula for triangular numbers, making it less efficient than a binary search or direct formula approach but conceptually simple.

## Complexity

- **Time:** O(√n)
- **Space:** O(1)

## Stats

- Submitted: 2024-10-01 18:34 UTC
- Runtime: 9 ms
- Memory: 8.6 MB
- Language: C++
