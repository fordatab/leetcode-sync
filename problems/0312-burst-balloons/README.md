# Burst Balloons

**Difficulty:** Hard
**Tags:** dynamic-programming, memoization, interval-dp, hash-table

## Problem

Given an array of balloon values, you must burst all balloons to maximize coins collected. Bursting balloon i yields coins equal to the product of its value and its neighbors' values (treating out-of-bounds as value 1). After bursting a balloon, its neighbors become adjacent. The goal is to find the optimal bursting order to maximize total coins, with array length up to 300 and values up to 100.

## Approach

The solution uses bottom-up dynamic programming with memoization via a hash map. It augments the input array by prepending and appending virtual balloons with value 1 to handle boundary conditions uniformly.

The key insight is to think backwards: instead of deciding which balloon to burst first, consider which balloon to burst *last* in each subrange. For a range [left, right], trying each balloon as the last one to burst means its neighbors at burst-time are left and right (all others in the range are already gone).

The algorithm uses three nested loops: the outer loop iterates over increasing subrange sizes (offset from 2 to n), the middle loop slides a window of that size across the array, and the innermost loop tries each balloon as the pivot (last to burst). For each configuration, it calculates coins as `nums[left] * nums[pivot] * nums[right]` plus the cached results from the two smaller subproblems.

A hash map stores results using a composite key (two integers packed into a long), and the final answer is retrieved for the range spanning the entire augmented array.

## Complexity

- **Time:** O(n³)
- **Space:** O(n²)

## Stats

- Submitted: 2024-08-29 08:05 UTC
- Runtime: 1286 ms
- Memory: 27.9 MB
- Language: C++
