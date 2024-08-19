# 2 Keys Keyboard

**Difficulty:** Medium
**Tags:** dynamic-programming, math, number-theory, factorization

## Problem

Starting with a single 'A' on a screen, you can perform two operations: Copy All (copy everything currently on screen) or Paste (paste what was last copied). The goal is to find the minimum number of operations needed to get exactly n 'A's on the screen. The constraint is that n ranges from 1 to 1000.

## Approach

The solution uses dynamic programming with a factorization insight. For each target count from 2 to n, it finds the largest proper divisor (largest factor less than the number itself). The DP state stores a pair: the minimum operations needed and the clipboard size used.

The key insight is that to reach n characters, you can reach the largest factor f first, then copy all f characters (1 operation) and paste them (n/f - 1) times to multiply from f to n. This gives f * (n/f) = n characters.

For prime numbers (where the largest factor is 1), the code sets the operation count to n itself, representing copying once and pasting n-1 times. For composite numbers, it builds on the solution for the largest factor: `dp[f].first + 1 + (n/f - 1)`, where the +1 is the copy operation and `(n/f - 1)` are the paste operations needed to scale from f to n.

The algorithm iterates through all values from 2 to n, computing the minimum steps for each by leveraging previously computed results for their largest factors.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-19 00:35 UTC
- Runtime: 20 ms
- Memory: 8.5 MB
- Language: C++
