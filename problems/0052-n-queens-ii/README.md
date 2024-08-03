# N-Queens II

**Difficulty:** Hard
**Tags:** backtracking, hash-table, recursion, constraint-satisfaction

## Problem

Given an integer n between 1 and 9, count the number of distinct ways to place n queens on an n×n chessboard such that no two queens can attack each other (i.e., no two queens share the same row, column, or diagonal).

## Approach

The solution uses backtracking with constraint tracking via hash sets. It processes the board row by row, attempting to place a queen in each column of the current row. Three hash sets track occupied columns, positive diagonals (identified by row+column), and negative diagonals (identified by row-column). For each row, the algorithm tries placing a queen in every valid column position—one that doesn't conflict with the tracked constraints. When a valid position is found, it marks that column and both diagonals as occupied, recursively processes the next row, then backtracks by unmarking those constraints. When all n rows have been successfully filled (base case r == n), it increments a counter. The board vector itself is maintained but only for compatibility; the actual conflict detection relies entirely on the three hash sets.

## Complexity

- **Time:** O(n!)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-03 03:51 UTC
- Runtime: 14 ms
- Memory: 11.7 MB
- Language: C++
