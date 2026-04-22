# Range Sum Query 2D - Immutable

**Difficulty:** Medium
**Tags:** prefix-sum, matrix, dynamic-programming, array

## Problem

Given a 2D integer matrix, implement a data structure that supports multiple queries to calculate the sum of all elements within any rectangular region defined by its top-left and bottom-right corners. The matrix dimensions can be up to 200×200, element values range from -10⁴ to 10⁴, and up to 10⁴ queries must be handled efficiently with O(1) query time.

## Approach

The solution uses a 2D prefix sum array to achieve constant-time range queries. During initialization, a prefix sum matrix is built where each cell `prefix[i][j]` stores the sum of all elements in the rectangle from `(0,0)` to `(i-1,j-1)` in the original matrix. The prefix array is sized `(m+1)×(n+1)` with an extra row and column of zeros to simplify boundary handling.

The prefix sum is computed using the inclusion-exclusion principle: for each cell, we add the current matrix value, the prefix sum from the cell above, and the prefix sum from the cell to the left, then subtract the diagonal prefix sum (which was counted twice).

For range queries, the sum of a rectangle is calculated using four lookups in the prefix array: we take the prefix sum at the bottom-right corner, subtract the prefix sums of the regions above and to the left of the target rectangle, then add back the top-left diagonal corner that was subtracted twice. All indices are adjusted by +1 to account for the padding in the prefix array.

## Complexity

- **Time:** O(m*n) for initialization, O(1) for each query
- **Space:** O(m*n)

## Stats

- Submitted: 2026-04-22 17:15 UTC
- Runtime: 20 ms
- Memory: 149.2 MB
- Language: C++
