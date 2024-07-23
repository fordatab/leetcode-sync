# Jump Game

**Difficulty:** Medium
**Tags:** greedy, array, backward-iteration

## Problem

Given an array where each element represents the maximum jump distance from that position, determine whether you can reach the final index starting from the first position. The array can contain up to 10,000 elements with values ranging from 0 to 100,000.

## Approach

The solution uses a greedy backward-tracking approach. Instead of trying to find a path forward from the start, it works backward from the end position.

It maintains a `goal` variable initially set to the last index. Starting from the second-to-last position and moving backward, it checks at each index whether a jump from that position can reach or exceed the current goal (`i + nums[i] >= goal`).

Whenever a position can reach the goal, that position becomes the new goal. This process continues until reaching the beginning of the array.

If the goal has been moved all the way back to index 0, it means there's a valid path from start to finish. The key insight is that we only need to verify whether each position can reach *some* valid subsequent position, not enumerate all possible paths.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-23 09:09 UTC
- Runtime: 44 ms
- Memory: 50.9 MB
- Language: C++
