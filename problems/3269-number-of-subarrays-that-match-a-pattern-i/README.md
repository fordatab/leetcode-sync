# Number of Subarrays That Match a Pattern I

**Difficulty:** Medium
**Tags:** sliding-window, array, simulation, pattern-matching

## Problem

Given an integer array nums and a pattern array containing values -1, 0, and 1, find how many subarrays of length m+1 match the pattern. A subarray matches if for each pattern position k, the relationship between consecutive elements (greater, equal, or less) corresponds to the pattern value (1, 0, or -1 respectively). The array nums has length n (2 ≤ n ≤ 100), and pattern has length m (1 ≤ m < n).

## Approach

The solution uses a sliding window approach with brute-force validation. For each possible starting position in nums (from 0 to n - m - 1), it examines a subarray of length m+1.

For each candidate subarray, it iterates through the pattern array and checks if consecutive elements satisfy the required relationship. It maintains a `prev` variable to track the current element being compared, and uses conditional logic to verify:
- When pattern[k] = 1, nums[i+k+1] must be greater than nums[i+k]
- When pattern[k] = 0, nums[i+k+1] must equal nums[i+k]
- When pattern[k] = -1, nums[i+k+1] must be less than nums[i+k]

If any comparison fails, it breaks early and marks that subarray as non-matching. The counter increments for each fully matching subarray, and the final count is returned.

## Complexity

- **Time:** O(n * m)
- **Space:** O(1)

## Stats

- Submitted: 2025-09-02 00:48 UTC
- Runtime: 3 ms
- Memory: 43.7 MB
- Language: C++
