# Check if Two Chessboard Squares Have the Same Color

**Difficulty:** Easy
**Tags:** math, bit-manipulation, string

## Problem

Given two chessboard coordinates in algebraic notation (letter for column, digit for row), determine whether the two squares share the same color. Each coordinate is a two-character string where the first character is a lowercase letter from 'a' to 'h' and the second is a digit from '1' to '8', representing valid positions on a standard 8×8 chessboard.

## Approach

The solution exploits the mathematical pattern of chessboard colors: a square's color depends on the parity (odd/even) of its column and row indices. Two squares have the same color if either both their column parities and row parities match, or both differ.

The code checks the parity of both coordinates' column letters (using `c1[0] % 2` on the ASCII values) and row digits (using `c1[1] % 2`). If the column parities are the same, the row parities must also match for the squares to have the same color. Conversely, if the column parities differ, the row parities must also differ.

This works because on a chessboard, alternating squares change color. When you move one column right (or one row up), the color flips. So matching parities in both dimensions, or mismatching parities in both dimensions, indicates the same color.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-03 06:29 UTC
- Runtime: 2 ms
- Memory: 7.7 MB
- Language: C++
