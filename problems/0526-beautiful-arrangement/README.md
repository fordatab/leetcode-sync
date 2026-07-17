# Beautiful Arrangement

**Difficulty:** Medium
**Tags:** backtracking, recursion, permutation, bit-manipulation

## Problem

Given an integer n, count how many permutations of numbers 1 through n satisfy the "beautiful arrangement" property: for each position i (1-indexed), either the number at position i is divisible by i, or i is divisible by the number at position i. The constraint is that n is between 1 and 15.

## Approach

The solution uses backtracking to explore all valid permutations. It builds the permutation position by position from left to right (starting at position 1). For each position i, it tries every number from 1 to n that hasn't been used yet and checks if the divisibility condition is satisfied (either num % i == 0 or i % num == 0). When a valid number is found, it's added to the current permutation, marked as used, and the algorithm recursively continues to fill the next position. When a complete permutation of length n is built, the counter is incremented. After exploring all possibilities with a particular number at a position, the algorithm backtracks by removing that number and unmarking it as used, allowing it to be tried in different positions.

## Complexity

- **Time:** O(k)
- **Space:** O(n)

## Stats

- Submitted: 2026-07-17 06:04 UTC
- Runtime: 83 ms
- Memory: 8.1 MB
- Language: C++
