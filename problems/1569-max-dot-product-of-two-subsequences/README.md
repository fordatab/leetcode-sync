# Max Dot Product of Two Subsequences

**Difficulty:** Hard
**Tags:** dynamic-programming, array, subsequence

## Problem

Given two integer arrays, find the maximum dot product between non-empty subsequences of equal length from each array. A subsequence maintains the relative order of elements from the original array. The arrays can contain up to 500 elements each, with values ranging from -1000 to 1000.

## Approach

This solution uses bottom-up dynamic programming with a 2D table where `dp[i][j]` represents the maximum dot product achievable considering elements from index `i` onward in `nums1` and index `j` onward in `nums2`.

The DP table is filled starting from the bottom-right corner (the last elements of both arrays). For each cell `(x, y)`, the algorithm considers three options:

1. **Include the current pair**: Multiply `nums1[x] * nums2[y]` and potentially add the best result from `dp[x+1][y+1]` (the diagonal). However, if the diagonal value is negative, it treats it as 0 to start a fresh subsequence, ensuring we don't worsen the product.

2. **Skip current element in nums1**: Take the value from `dp[x+1][y]` (move down).

3. **Skip current element in nums2**: Take the value from `dp[x][y+1]` (move right).

The maximum of these three options becomes `dp[x][y]`. The final answer is stored in `dp[0][0]`, representing the maximum dot product starting from the beginning of both arrays.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2026-01-14 23:58 UTC
- Runtime: 18 ms
- Memory: 17.7 MB
- Language: C++
