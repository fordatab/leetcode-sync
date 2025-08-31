# Subarray With Elements Greater Than Varying Threshold

**Difficulty:** Hard
**Tags:** monotonic-stack, array, greedy, stack

## Problem

Given an array of integers and a threshold value, find the length of any subarray where all elements exceed threshold divided by the subarray's length. The key constraint is that for a subarray of length k, every element must be strictly greater than threshold/k. Array size can be up to 10^5, and values can reach 10^9.

## Approach

The solution uses a monotonic stack approach to find, for each element, the maximum range where it is the minimum value. It computes two arrays: `left[i]` stores the nearest index to the left where an element is smaller than `nums[i]`, and `right[i]` stores the nearest index to the right where an element is smaller than `nums[i]`.

Two passes with a monotonic stack build these boundary arrays. The first pass (left to right) finds left boundaries by maintaining a stack of indices in increasing order of their values. The second pass (right to left) finds right boundaries similarly.

For each position, the algorithm calculates the length of the maximal subarray where that element is the minimum: `length = right[x] - left[x] - 1`. If `nums[x] * length > threshold`, then this element (being the minimum) ensures all elements in that range satisfy `element > threshold/length`, making it a valid subarray.

The key insight is reformulating the condition: if the minimum element in a subarray of length k satisfies `min_element > threshold/k`, then all elements satisfy it. This is equivalent to checking `min_element * k > threshold`.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-08-31 02:19 UTC
- Runtime: 35 ms
- Memory: 105.4 MB
- Language: C++
