# Ant on the Boundary

**Difficulty:** Easy
**Tags:** array, prefix-sum, simulation

## Problem

An ant starts at position zero (the boundary) on a number line and processes an array of non-zero integers sequentially, moving left for negative values and right for positive values by their absolute magnitude. The task is to count how many times the ant's cumulative position equals zero after completing each move, which represents returns to the boundary. The array has up to 100 elements with values between -10 and 10 (excluding 0).

## Approach

The solution computes a running sum of the movement array using `partial_sum`, which transforms the array in-place so that each position contains the cumulative sum up to that index. This cumulative sum at each index represents the ant's position after processing that movement. After computing all cumulative positions, the code uses `count` to tally how many positions equal zero, which directly corresponds to the number of times the ant returns to the boundary.

For example, with input `[2, 3, -5]`, `partial_sum` transforms it to `[2, 5, 0]`, and counting zeros gives 1. The key insight is that the ant's position at any step is simply the sum of all movements up to that point, and returning to the boundary means this sum equals zero.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 03:38 UTC
- Runtime: 4 ms
- Memory: 22.8 MB
- Language: C++
