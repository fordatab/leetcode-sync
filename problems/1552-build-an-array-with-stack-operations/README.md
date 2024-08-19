# Build an Array With Stack Operations

**Difficulty:** Medium
**Tags:** stack, simulation, greedy, array

## Problem

Given a target array of strictly increasing integers and an upper bound n, simulate building the target array using stack operations on a stream of integers from 1 to n. The goal is to return a sequence of "Push" and "Pop" operations that, when applied to the stream in order, results in a stack matching the target array from bottom to top. You must stop as soon as the stack matches the target.

## Approach

The solution iterates through integers from 1 to n, maintaining an index `i` that tracks the current position in the target array. For each stream integer `x`, it checks whether `x` matches `target[i]`. If there's a match, it appends a "Push" operation and increments the index. If `x` doesn't match the current target element, it means this number should be skipped, so it appends both "Push" and "Pop" to simulate discarding it. The loop terminates early once all target elements have been matched (when `i` reaches `target.size()`), avoiding unnecessary operations beyond the last target value.

## Complexity

- **Time:** O(n)
- **Space:** O(m)

## Stats

- Submitted: 2024-08-19 06:19 UTC
- Runtime: 0 ms
- Memory: 9.7 MB
- Language: C++
