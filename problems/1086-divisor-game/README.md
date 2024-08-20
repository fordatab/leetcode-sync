# Divisor Game

**Difficulty:** Easy
**Tags:** dynamic-programming, game-theory, math

## Problem

Alice and Bob alternate turns starting with Alice, playing a game with an integer n on a chalkboard. On each turn, a player chooses a divisor x of n (where 0 < x < n) and replaces n with n - x. The player who cannot make a move loses. The task is to determine whether Alice wins when both players play optimally, given 1 ≤ n ≤ 1000.

## Approach

The solution uses dynamic programming with a bottom-up approach. It builds a DP table where `dp[x]` represents whether the current player wins when starting with value x.

For each number x from 1 to n, the code iterates through all potential divisors y (from 1 to x/2). When y divides x evenly (x % y == 0), it checks the game state after making that move: `dp[x-y]`. The current player wins if there exists any move that puts the opponent in a losing position, captured by the expression `!dp[x-y]`. The bitwise OR operation (`|=`) ensures that if any winning move exists, `dp[x]` becomes true.

The base case is implicit: `dp[1]` remains 0 (false) because no valid move exists when n=1. The answer for the original problem is simply `dp[n]`, indicating whether Alice (the first player) wins starting with n.

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-20 05:17 UTC
- Runtime: 6 ms
- Memory: 7.6 MB
- Language: C++
