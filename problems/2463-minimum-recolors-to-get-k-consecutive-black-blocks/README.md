# Minimum Recolors to Get K Consecutive Black Blocks

**Difficulty:** Easy
**Tags:** sliding-window, string, greedy

## Problem

Given a string of 'W' (white) and 'B' (black) blocks and an integer k, find the minimum number of operations needed to create at least one sequence of k consecutive black blocks. Each operation converts one white block to black. The string has length n (1 ≤ n ≤ 100) and k is guaranteed to be at most n.

## Approach

The solution uses a sliding window approach to examine all possible consecutive subsequences of length k. It maintains a window of size k and tracks the count of black blocks ('B') within the current window using variable `c`. For each position, it calculates how many white blocks would need to be recolored (k - c) and keeps track of the minimum operations needed across all windows in variable `o`. The left pointer `l` marks the start of the window, and when the window reaches size k, it slides forward by incrementing `l` and adjusting the black block count accordingly. By checking every possible k-length window, the algorithm finds the window with the maximum number of black blocks, which corresponds to the minimum number of recoloring operations needed.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-22 23:18 UTC
- Runtime: 0 ms
- Memory: 7.7 MB
- Language: C++
