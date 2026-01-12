# Split Array Largest Sum

**Difficulty:** Hard
**Tags:** binary-search, greedy, array

## Problem

Given an array of integers and a target number k, partition the array into exactly k consecutive subarrays such that the maximum sum among all subarrays is as small as possible. The array has up to 1000 elements with values up to 10^6, and k is at most 50 or the array length, whichever is smaller.

## Approach

The solution uses binary search on the answer space to find the minimum possible maximum subarray sum. The search range is bounded by the largest single element (lower bound, since any subarray must contain at least one element) and the total sum of all elements (upper bound, representing all elements in one subarray).

For each candidate maximum sum during binary search, a greedy validation function `canSplit` checks if it's possible to partition the array into at most k subarrays without exceeding that maximum. This function iterates through the array, accumulating elements into the current subarray until adding the next element would exceed the candidate maximum, at which point it starts a new subarray.

The binary search narrows down to the smallest maximum sum for which a valid k-way partition exists. When `canSplit` returns true for a candidate, we search for potentially smaller values; when false, we need a larger maximum sum.

## Complexity

- **Time:** O(n log S)
- **Space:** O(1)

## Stats

- Submitted: 2026-01-12 23:09 UTC
- Runtime: 0 ms
- Memory: 10.4 MB
- Language: C++
