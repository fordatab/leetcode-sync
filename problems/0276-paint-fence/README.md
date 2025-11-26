# Paint Fence

**Difficulty:** Medium
**Tags:** dynamic-programming, combinatorics, state-machine

## Problem

Given n fence posts and k colors, count the number of ways to paint the fence such that every post gets exactly one color and no three consecutive posts share the same color. The fence must have between 1 and 50 posts, with up to 100,000 available colors.

## Approach

The solution uses dynamic programming with two states per position: whether the current post has the same color as the previous post (state 0) or a different color (state 1).

For the base case at position 1, there are k ways to paint with a different color and 0 ways to have the same color as a non-existent previous post. For each subsequent position, the number of ways to paint the same color as the previous equals the number of ways the previous was painted differently (to avoid three consecutive). The number of ways to paint a different color equals the total ways to paint the previous position multiplied by (k-1) choices.

The recurrence relations are: `dp[i][0] = dp[i-1][1]` (same color requires previous was different) and `dp[i][1] = (dp[i-1][0] + dp[i-1][1]) * (k-1)` (different color has k-1 choices from any previous state). The final answer sums both states at position n.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-11-26 02:17 UTC
- Runtime: 0 ms
- Memory: 8.8 MB
- Language: C++
