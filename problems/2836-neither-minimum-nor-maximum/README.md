# Neither Minimum nor Maximum

**Difficulty:** Easy
**Tags:** array, greedy, math

## Problem

Given an array of distinct positive integers, find any element that is neither the minimum nor the maximum value in the array. If no such element exists (which happens when the array has fewer than 3 elements), return -1. The array contains between 1 and 100 elements, each with values from 1 to 100.

## Approach

The solution uses a clever three-element comparison strategy to avoid sorting the entire array. It first checks if the array has fewer than 3 elements, immediately returning -1 since no middle value can exist.

For arrays with at least 3 elements, it examines only the first three values: it identifies the minimum and maximum between the first two elements (storing them as `a` and `b` respectively), then compares the third element `c` against them.

Through a series of conditional checks, it determines which of the three elements is guaranteed to be neither the global minimum nor maximum:
- If `c` falls between `a` and `b`, then `c` itself is a valid middle value
- If `c` is smaller than both, then `a` (being larger than `c` but smaller than `b`) is a valid middle value
- If `c` is larger than both, then `b` (being smaller than `c` but larger than `a`) is a valid middle value

This works because among any three distinct numbers, at least one must be neither the minimum nor the maximum of those three, and that property extends to the entire array.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 04:11 UTC
- Runtime: 83 ms
- Memory: 97.7 MB
- Language: C++
