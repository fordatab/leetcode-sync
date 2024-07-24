# Jump Game II

**Difficulty:** Medium
**Tags:** greedy, array, breadth-first-search, range-processing

## Problem

Given an array where each element represents the maximum jump distance from that position, find the minimum number of jumps needed to reach the last index from the first. The array is 0-indexed with length up to 10,000, and it's guaranteed that the last index is reachable.

## Approach

This solution uses a greedy breadth-first search approach by treating positions reachable in the same number of jumps as a "level". It maintains a window `[l, r]` representing all positions reachable with the current number of jumps.

For each level, it iterates through all positions in the current window and calculates the farthest position `m` that can be reached from any position in this window (by checking `x + nums[x]` for each position `x`). Once the farthest reachable position is found, the window is updated: the left boundary becomes `r + 1` (just after the previous window) and the right boundary becomes `m` (the new farthest position).

The jump counter increments after processing each level, and the loop continues until the right boundary reaches or exceeds the last index. This ensures we find the minimum number of jumps by exploring positions level-by-level in order of reachability.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-24 01:52 UTC
- Runtime: 9 ms
- Memory: 19.3 MB
- Language: C++
