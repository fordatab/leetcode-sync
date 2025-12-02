# Minimum Number of Removals to Make Mountain Array

**Difficulty:** Hard
**Tags:** dynamic-programming, longest-increasing-subsequence, array

## Problem

Given an integer array, determine the minimum number of elements to remove so that the remaining array forms a mountain shape: strictly increasing up to some peak index, then strictly decreasing afterward. The array must have at least 3 elements, and the peak cannot be at either endpoint. It's guaranteed that a valid mountain can be formed.

## Approach

The solution uses dynamic programming to find the longest possible mountain subsequence, then subtracts its length from the total array size.

First, it computes `inc[i]` for each index i, representing the length of the longest increasing subsequence ending at position i. This is done via a nested loop checking all previous indices.

Second, it computes `dec[i]` for each index i, representing the length of the longest decreasing subsequence starting at position i. This is calculated by iterating backward and checking all subsequent indices.

Finally, for each potential peak position (excluding the endpoints), if both `inc[i] > 1` and `dec[i] > 1` (ensuring valid ascending and descending sides), it calculates the total mountain length as `inc[i] + dec[i] - 1` (subtracting 1 because the peak is counted in both). The answer is the array length minus the maximum mountain length found.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-02 10:06 UTC
- Runtime: 73 ms
- Memory: 16.2 MB
- Language: C++
