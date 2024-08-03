# N-Queens

**Difficulty:** Hard
**Tags:** backtracking, hash-table, recursion, n-queens

## Problem

Given a board size n, find all valid ways to place n chess queens on an n×n board such that no queen can attack another. Queens attack along rows, columns, and diagonals. The output should be all distinct board configurations where 'Q' represents a queen and '.' represents an empty square. The constraint is 1 ≤ n ≤ 9.

## Approach

The solution uses backtracking to explore all possible queen placements row by row. It maintains three hash sets to track occupied columns, positive diagonals (identified by r+c), and negative diagonals (identified by r-c). For each row, it attempts to place a queen in each column, checking if that position conflicts with any previously placed queens by looking up the three sets.

When placing a queen at position (r, c), the algorithm adds c to the column set, r+c to the positive diagonal set, and r-c to the negative diagonal set, then marks the board and recursively processes the next row. After exploring all possibilities from that state, it backtracks by removing the queen and undoing all the set insertions.

The base case occurs when r equals n, meaning all n rows have valid queen placements, at which point the current board configuration is added to the result list. The hash sets provide O(1) lookup to quickly determine if a position is safe, avoiding the need to scan the entire board for conflicts.

## Complexity

- **Time:** O(n!)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-03 03:48 UTC
- Runtime: 12 ms
- Memory: 12.7 MB
- Language: C++
