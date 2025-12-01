# Remove Invalid Parentheses

**Difficulty:** Hard
**Tags:** backtracking, string, recursion, pruning, set

## Problem

Given a string containing parentheses and lowercase letters, find all unique valid strings that can be formed by removing the minimum number of parentheses. The string length is at most 25 with at most 20 parentheses. A valid string has properly balanced parentheses where every opening parenthesis has a matching closing one in the correct order.

## Approach

The solution uses backtracking with pruning to explore all possible removal combinations. First, it calculates the minimum number of left and right parentheses that must be removed by simulating a balance counter: increment for '(' and decrement for ')' when possible, otherwise mark for removal. Then it performs a recursive backtracking search where at each position it decides whether to remove or keep the current character. For parentheses, it tries both removing (decrementing the respective removal counter) and keeping (updating the balance counter). For letters, it always keeps them. The search tracks the current balance (open minus closed parentheses seen so far) and prunes branches where balance goes negative, removal counts go negative, or there aren't enough remaining characters to satisfy removal requirements. All valid results are collected in an unordered set to eliminate duplicates.

## Complexity

- **Time:** O(2^n)
- **Space:** O(2^n)

## Stats

- Submitted: 2025-12-01 11:49 UTC
- Runtime: 1173 ms
- Memory: 662.7 MB
- Language: C++
