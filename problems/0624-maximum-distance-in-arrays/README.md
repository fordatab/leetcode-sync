# Maximum Distance in Arrays

**Difficulty:** Medium
**Tags:** array, greedy, single-pass

## Problem

Given m sorted arrays in ascending order, find the maximum absolute difference between two integers where each integer must come from a different array. The arrays contain between 1 and 500 integers each, with values ranging from -10⁴ to 10⁴, and there are at least 2 arrays with a total of at most 10⁵ integers across all arrays.

## Approach

The solution uses a single-pass greedy approach that tracks the global minimum and maximum values seen so far across all previously processed arrays. For each array, it calculates two potential maximum distances: the difference between the current array's last element (maximum) and the global minimum from previous arrays, and the difference between the global maximum from previous arrays and the current array's first element (minimum). It updates the answer with the larger of these two differences, then updates the global minimum and maximum trackers to include the current array's bounds. This works because each array is sorted, so only the first and last elements need to be considered, and by processing arrays sequentially, we ensure the two values being compared always come from different arrays.

## Complexity

- **Time:** O(m)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-17 06:08 UTC
- Runtime: 228 ms
- Memory: 107.7 MB
- Language: C++
