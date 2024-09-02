# Subarray Sum Equals K

**Difficulty:** Medium
**Tags:** prefix-sum, hash-table, array, subarray

## Problem

Given an array of integers and a target value k, count how many contiguous subarrays have elements that sum exactly to k. The array can contain up to 20,000 elements with values ranging from -1000 to 1000, and k can range from -10^7 to 10^7.

## Approach

The solution uses prefix sums combined with a hash map to efficiently count valid subarrays. First, it computes a prefix sum array where each element stores the cumulative sum up to that index. Then it iterates through the prefix sums, using the key insight that if `prefix[j] - prefix[i] = k`, then the subarray from index `i+1` to `j` has sum k.

For each position, the code checks two conditions: (1) if the prefix sum itself equals k (meaning the subarray from index 0 to current position sums to k), and (2) if there exists a previous prefix sum that differs from the current one by exactly k. The hash map tracks how many times each prefix sum has been seen, allowing us to count all valid subarrays ending at the current position in constant time.

By storing prefix sum frequencies in the map and looking up `prefix[x] - k`, the solution avoids the O(n²) nested loop approach and achieves linear time complexity.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-02 05:04 UTC
- Runtime: 84 ms
- Memory: 51.8 MB
- Language: C++
