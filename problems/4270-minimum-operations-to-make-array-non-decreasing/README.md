# Minimum Operations to Make Array Non Decreasing

**Difficulty:** Medium
**Tags:** greedy, array, single-pass

## Problem

Given an integer array of length n, you can perform operations where you select any contiguous subarray and increase all its elements by a positive integer x. The goal is to find the minimum total sum of all x values needed across all operations to transform the array into a non-decreasing sequence (where each element is less than or equal to the next).

## Approach

The solution uses a greedy single-pass approach. It iterates through the array while maintaining a running "previous" value that represents the minimum value the current position must reach to maintain non-decreasing order.

For each element, if it's less than the previous value, the algorithm calculates the deficit (prev - n) and adds it to the total cost. This deficit represents the minimum amount we'd need to add to this element to match the previous value.

Crucially, the algorithm always updates `prev` to the current element's original value (not the adjusted value). This works because when we eventually need to increase a later element, we can choose a subarray that includes all positions from some earlier point, effectively "carrying forward" the necessary increases.

The key insight is that we only accumulate cost when encountering decreases, and the greedy choice of always matching to the previous element's original value yields the optimal total.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-06-02 10:18 UTC
- Runtime: 2 ms
- Memory: 136.8 MB
- Language: C++
