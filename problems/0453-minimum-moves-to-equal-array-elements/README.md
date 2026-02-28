# Minimum Moves to Equal Array Elements

**Difficulty:** Medium
**Tags:** array, math, greedy

## Problem

Given an array of integers, determine the minimum number of operations needed to make all elements equal, where each operation increments all but one element by 1. The array can have up to 100,000 elements with values ranging from -10^9 to 10^9, and the result fits in a 32-bit integer.

## Approach

The solution exploits a key mathematical insight: incrementing n-1 elements is equivalent to decrementing one element. Therefore, making all elements equal is the same as bringing every element down to the minimum value.

The code first finds the minimum element in the array using `min_element`. Then it iterates through all elements and accumulates the difference between each element and the minimum. This sum represents the total number of moves needed.

For example, with `[1,2,3]`, the minimum is 1. The differences are (1-1)=0, (2-1)=1, and (3-1)=2, totaling 3 moves. Each move effectively reduces one non-minimum element by 1 until all reach the minimum.

Note: The `check` function is defined but never used in the actual solution.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-02-28 11:19 UTC
- Runtime: 0 ms
- Memory: 32.2 MB
- Language: C++
