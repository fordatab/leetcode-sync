# Remove Boxes

**Difficulty:** Hard
**Tags:** dynamic-programming, memoization, interval-dp, recursion

## Problem

Given an array of boxes with colors represented by positive integers, repeatedly remove contiguous segments of identical colors to maximize points. Each removal of k consecutive boxes of the same color scores k² points. The goal is to find the maximum total points achievable by optimally choosing which segments to remove and in what order.

## Approach

This solution uses **3D dynamic programming with memoization** to explore different removal strategies. The state `dp[l][r][k]` represents the maximum points obtainable from boxes in range `[l, r]` when there are `k` additional boxes of the same color as `boxes[r]` to the right (outside the current range).

The key optimization is **compressing consecutive duplicates** at the right boundary: if `boxes[r]` matches `boxes[r-1]`, we increment `k` and move `r` leftward, effectively treating all trailing duplicates as a single group.

For each subproblem, we consider two strategies:
1. **Remove the rightmost group immediately**: Remove `boxes[r]` along with its `k` trailing duplicates for `(k+1)²` points, then solve the remaining `[l, r-1]` range.
2. **Merge with earlier matching boxes**: For each position `i < r` where `boxes[i] == boxes[r]`, split the problem into solving `[l, i]` with `k+1` extra boxes (merging `boxes[r]`'s group with `boxes[i]`) and independently solving the middle segment `[i+1, r-1]`.

The recursion explores all possible ways to partition and merge same-colored groups, memoizing results to avoid redundant computation.

## Complexity

- **Time:** O(n⁴)
- **Space:** O(n³)

## Stats

- Submitted: 2025-09-03 01:27 UTC
- Runtime: 29 ms
- Memory: 14.7 MB
- Language: C++
