# Valid Sudoku

**Difficulty:** Medium
**Tags:** array, hash-table, matrix, validation

## Problem

Given a 9×9 grid representing a partially filled Sudoku board (with digits 1-9 and empty cells marked as '.'), check whether the current configuration violates any Sudoku rules. Each row, each column, and each of the nine 3×3 sub-grids must contain no duplicate digits among the filled cells. The board does not need to be solvable; only the existing placements must be conflict-free.

## Approach

The solution uses three separate validation passes with frequency counting arrays:

**3×3 Sub-box Validation**: The outer two loops iterate over the nine 3×3 boxes (3 boxes horizontally and 3 vertically). For each box, a frequency array `box[9]` counts occurrences of each digit. Nested loops scan all 9 cells within the current box, incrementing the count for each non-empty digit. If any digit appears more than once in a box, the function returns false.

**Row and Column Validation**: A second set of loops processes all nine rows and columns simultaneously. For each position `x` from 0 to 8, two frequency arrays `row[9]` and `col[9]` track digit occurrences in row `x` and column `x` respectively. The inner loop scans positions 0-8, checking `board[x][y]` for the row and `board[y][x]` for the column. After populating both arrays, if any digit count exceeds 1 in either the row or column, the function returns false.

If all validations pass without detecting duplicates, the board is considered valid and the function returns true. Each validation uses a simple counting approach rather than sets, converting characters to array indices by subtracting '1'.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-06-28 02:18 UTC
- Runtime: 22 ms
- Memory: 21.9 MB
- Language: C++
