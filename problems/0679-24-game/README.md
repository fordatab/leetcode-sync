# 24 Game

**Difficulty:** Hard
**Tags:** backtracking, recursion, brute-force, math

## Problem

Given exactly four integers between 1 and 9, determine whether they can be combined using addition, subtraction, multiplication, and real division (with parentheses allowed) to produce a result of 24. Each number must be used exactly once, operations are binary only, and the answer should account for floating-point precision.

## Approach

The solution uses recursive backtracking to exhaustively try all possible combinations of two numbers and operations. At each step, it picks two distinct numbers from the current list, applies all six possible operations (a+b, a-b, b-a, a*b, a/b, b/a, with division guarded against zero), and recursively checks if the resulting smaller list can reach 24. The base case occurs when only one number remains: if it's within 0.1 of 24, return true. The algorithm implicitly explores all orderings and groupings by selecting pairs and replacing them with intermediate results. Division by zero is avoided by checking divisors before performing division. The recursion naturally handles all possible expression structures through the choice of which two numbers to combine at each level.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2026-02-02 21:45 UTC
- Runtime: 35 ms
- Memory: 20 MB
- Language: C++
