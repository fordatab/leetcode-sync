# Range Sum Query 2D - Immutable

**Difficulty:** Medium
**Tags:** prefix-sum, matrix, dynamic-programming, array

## Problem

Given a 2D matrix, implement a class that efficiently handles multiple queries for the sum of elements within rectangular regions. Each query specifies the upper-left and lower-right corners of a rectangle, and the solution must compute region sums in constant time. The matrix dimensions can be up to 200×200, and up to 10,000 queries may be performed.

## Approach

The solution uses a 2D prefix sum array to enable constant-time range queries. During initialization, it builds a prefix sum matrix where each cell `(i+1, j+1)` stores the sum of all elements in the rectangle from `(0, 0)` to `(i, j)` in the original matrix. The prefix array is sized `(m+1) × (n+1)` with an extra row and column of zeros to simplify boundary handling.

The prefix sum at each position is computed using the inclusion-exclusion principle: add the current matrix element, add the prefix sums from the cell above and to the left, then subtract the diagonal prefix sum (which was counted twice).

For range queries, the sum of a rectangle is calculated by taking the prefix sum at the bottom-right corner, subtracting the prefix sums of the regions above and to the left of the target rectangle, and adding back the top-left diagonal prefix sum (which was subtracted twice). All indices are shifted by 1 to account for the padding in the prefix array.

## Complexity

- **Time:** O(m*n) for initialization, O(1) per query
- **Space:** O(m*n)

## Stats

- Submitted: 2026-04-22 17:15 UTC
- Runtime: 20 ms
- Memory: 149.2 MB
- Language: C++
