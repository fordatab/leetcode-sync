# Minimum Number of Increments on Subarrays to Form a Target Array

**Difficulty:** Hard
**Tags:** stack, monotonic-stack, greedy, array

## Problem

Given an integer array called target and starting with an all-zeros array of the same length, determine the minimum number of operations needed to transform the zeros into the target array. Each operation allows you to select any contiguous subarray and increment all its elements by one. The array can have up to 100,000 elements, each with values up to 100,000.

## Approach

The solution uses a monotonic stack to track the "height profile" of the array as it's built from left to right. For each element in the target array, the algorithm pops from the stack all values greater than or equal to the current element, recording the first popped value. When values are popped, it means we've reached a descent in the height profile, requiring additional operations equal to the difference between the peak (first popped value) and the current valley (current element). After processing all pops, the current element is pushed onto the stack. Finally, after processing all elements, if the stack's top is non-zero, those remaining height units are added to the operation count, representing the operations needed to build up to the final rightmost elements. The key insight is that each descent in the array profile costs operations proportional to the height drop, while ascents are handled by continuing previous operations or starting new ones from zero.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-16 03:35 UTC
- Runtime: 20 ms
- Memory: 78.3 MB
- Language: C++
