# Number of Ways to Paint N × 3 Grid

**Difficulty:** Hard
**Tags:** dynamic-programming, math, combinatorics, pattern-matching

## Problem

Given an n×3 grid, count the number of ways to paint each cell with one of three colors (Red, Yellow, Green) such that no two adjacent cells (horizontally or vertically) share the same color. The answer must be returned modulo 10^9 + 7, with n ranging from 1 to 5000.

## Approach

The solution uses dynamic programming by categorizing valid row colorings into two types: those using all 3 colors (like RGB) and those using only 2 colors (like ABA pattern). For a single row, there are 6 ways to use 3 colors (3! permutations) and 6 ways to use 2 colors (C(3,2) × 2 patterns).

For each subsequent row, the code computes transitions based on compatibility rules: a 3-color row can be followed by 2 other 3-color patterns and 2 two-color patterns, while a 2-color row can be followed by 2 three-color patterns and 3 other two-color patterns. These transition counts are derived from checking which patterns don't create adjacent cells with matching colors.

The algorithm iterates from row 2 to n, updating the counts for both pattern types using the recurrence relations: `new_color3 = 2*color3 + 2*color2` and `new_color2 = 2*color3 + 3*color2`, applying modulo at each step. Finally, it returns the sum of both counts as the total number of valid colorings.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-02-06 03:41 UTC
- Runtime: 0 ms
- Memory: 7.9 MB
- Language: C++
