# Generate Parentheses

**Difficulty:** Medium
**Tags:** backtracking, recursion, string, depth-first-search

## Problem

Given an integer n representing the number of parenthesis pairs, generate all valid combinations of properly balanced parentheses. A valid combination means every opening parenthesis has a matching closing parenthesis in the correct order. The constraint is that n ranges from 1 to 8, which limits the search space.

## Approach

The solution uses recursive backtracking to build valid parenthesis strings character by character. It maintains two counters: `openN` for open parentheses added so far and `closedN` for closed parentheses. The base case occurs when both counters equal n, indicating a complete valid combination.

At each recursive step, the algorithm makes decisions based on two rules: it can add an open parenthesis if fewer than n have been used, and it can add a close parenthesis only if there are more open than closed parentheses currently in the string. This ensures the partial string remains valid at every step.

The recursion explores all possible valid paths by trying to add '(' first whenever allowed, then trying ')' when valid. Each complete valid string is collected in the result vector. String concatenation creates new temporary strings at each level rather than using a mutable character array.

## Complexity

- **Time:** O(4^n / sqrt(n))
- **Space:** O(n)

## Stats

- Submitted: 2024-06-29 06:16 UTC
- Runtime: 0 ms
- Memory: 15.2 MB
- Language: C++
