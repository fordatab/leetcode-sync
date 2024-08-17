# Merge Intervals

**Difficulty:** Medium
**Tags:** sorting, intervals, greedy, array

## Problem

Given a collection of intervals where each interval is represented as a pair of start and end values, combine any intervals that overlap or touch. Two intervals overlap if one starts before or exactly when the other ends. The goal is to return the minimal set of merged, non-overlapping intervals that cover the same range as the input.

## Approach

The solution first sorts all intervals by their start time. It then initializes the output with the first interval and iterates through the sorted list. For each interval, it checks if the current interval's start is less than or equal to the last merged interval's end — if so, they overlap or touch, and the solution extends the last merged interval's end to be the maximum of the two ends. If there's no overlap, the current interval is added as a new separate interval to the output. The variables `l` and `r` are declared but never used in the actual logic.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-17 05:53 UTC
- Runtime: 20 ms
- Memory: 22.8 MB
- Language: C++
