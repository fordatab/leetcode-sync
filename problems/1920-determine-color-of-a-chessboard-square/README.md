# Determine Color of a Chessboard Square

**Difficulty:** Easy
**Tags:** math, string, bit-manipulation

## Problem

Given a chessboard square coordinate as a two-character string (letter a-h followed by digit 1-8), determine whether the square is white or black. The coordinate always represents a valid square, with the letter indicating the column and the digit indicating the row.

## Approach

The solution exploits the mathematical property of chessboard coloring: squares alternate in color based on the sum of their coordinates. It converts both the column letter and row digit to their ASCII values and adds them together. If this sum is odd, the square is white; if even, it's black. This works because on a standard chessboard, squares where the column index and row index have different parities (one odd, one even) are white, while squares where both indices have the same parity are black. Adding the ASCII values preserves this parity relationship, allowing a simple modulo-2 check to determine the color.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 07:03 UTC
- Runtime: 2 ms
- Memory: 7.4 MB
- Language: C++
