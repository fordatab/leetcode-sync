# Row With Maximum Ones

**Difficulty:** Easy
**Tags:** matrix, array, counting, iteration

## Problem

Given an m×n binary matrix, identify which row contains the most ones and return both the row index and the count of ones in that row. If multiple rows tie for the maximum count, return the row with the smallest index. The matrix dimensions are at most 100×100, and each element is either 0 or 1.

## Approach

The solution iterates through each row of the matrix sequentially, maintaining a running counter `i` for the current row index. For each row, it counts the number of ones by iterating through all elements and incrementing a local counter `m` whenever a 1 is encountered. After processing each row, if the count `m` exceeds the current maximum `t`, both the maximum count `t` and the best row index `row` are updated. Because rows are processed in order from index 0 onwards and the comparison uses strict inequality (`m > t`), ties automatically favor the earlier row. Finally, the solution returns a vector containing the row index and the maximum count.

## Complexity

- **Time:** O(m * n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 04:34 UTC
- Runtime: 104 ms
- Memory: 70.6 MB
- Language: C++
