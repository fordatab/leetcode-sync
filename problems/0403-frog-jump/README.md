# Frog Jump

**Difficulty:** Hard
**Tags:** dynamic-programming, array, memoization

## Problem

A frog must cross a river by jumping on stones positioned at given coordinates. Starting at position 0, the frog's first jump must be exactly 1 unit. For subsequent jumps, if the previous jump was k units, the next jump must be k-1, k, or k+1 units. The goal is to determine whether the frog can reach the final stone. The stones array contains up to 2000 positions in strictly increasing order.

## Approach

The solution uses dynamic programming with a 2D table where `dp[i][k]` indicates whether stone `i` can be reached with a last jump of size `k`. The algorithm initializes by verifying the first mandatory jump of 1 unit to stone at position 1.

For each stone position `i` starting from index 2, the solution examines all previous stones `j` and calculates the jump distance needed. If that jump distance is `d`, it checks whether stone `j` was reachable with a prior jump of `d-1`, `d`, or `d+1` units. If any of these conditions hold, then stone `i` is reachable with a jump of `d` units.

The algorithm bounds jump sizes to at most `n` (the number of stones) since larger jumps become impossible given the constraint that jump sizes grow incrementally. Finally, it checks if any valid jump size can reach the last stone by scanning the final row of the DP table.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n^2)

## Stats

- Submitted: 2026-01-23 03:16 UTC
- Runtime: 87 ms
- Memory: 24.1 MB
- Language: C++
