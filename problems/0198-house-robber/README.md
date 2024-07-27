# House Robber

**Difficulty:** Medium
**Tags:** dynamic-programming, array, space-optimization

## Problem

Given an array where each element represents money in a house, find the maximum sum you can obtain by selecting non-adjacent elements. You cannot pick two consecutive houses because doing so triggers an alarm. The array has up to 100 elements, each with values from 0 to 400.

## Approach

This solution uses dynamic programming with space optimization. It maintains two variables: `rob1` tracks the maximum money obtainable up to two houses back, and `rob2` tracks the maximum up to the previous house.

For each house, it calculates two options: either rob the current house (adding its value to `rob1`) or skip it (keeping `rob2`). It takes the maximum of these two choices.

After processing each house, `rob1` is updated to the old `rob2` value, and `rob2` becomes the new maximum. This sliding window approach maintains only the two most recent states instead of storing the entire DP array.

The final answer is in `rob2`, which represents the maximum money obtainable considering all houses.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-27 04:59 UTC
- Runtime: 0 ms
- Memory: 9.4 MB
- Language: C++
