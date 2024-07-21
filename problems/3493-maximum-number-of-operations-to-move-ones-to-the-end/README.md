# Maximum Number of Operations to Move Ones to the End

**Difficulty:** Medium
**Tags:** stack, greedy, string, simulation

## Problem

Given a binary string, you can repeatedly choose any '1' followed by a '0' and move that '1' rightward until it hits the end of the string or another '1'. The goal is to determine the maximum number of such move operations that can be performed. The string can be up to 10^5 characters long.

## Approach

The solution works by processing the string from right to left, ignoring any trailing '1's since they're already at the end. It pushes all remaining '1' indices onto a stack, then pops them to identify contiguous groups of '1's.

For each group of consecutive '1's encountered (from left to right in the original string), the algorithm tracks the cumulative count of '1's seen so far. Each group contributes to the total operation count: when a group of k ones needs to move past zeros to the right, and there are already m ones to its right, this group will perform k operations for each of those m ones, plus k operations to reach its final position.

The key insight is that each '1' in a group must "leap over" all the zeros between it and the rightmost section, and the number of operations accumulates based on how many '1's have already been processed. By maintaining a running sum of group sizes and adding it to the total for each new group, the solution counts all individual move operations.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-21 03:41 UTC
- Runtime: 35 ms
- Memory: 18.6 MB
- Language: C++
