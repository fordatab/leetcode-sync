# Zigzag Conversion

**Difficulty:** Medium
**Tags:** string, simulation, array

## Problem

Given a string and a number of rows, arrange the characters in a zigzag pattern vertically across the specified number of rows, then read the result row by row. The zigzag moves down through rows, then diagonally up, repeating this pattern. For example, with 3 rows, characters are placed down rows 0→1→2, then up 1→0, then down again. Constraints include strings up to 1000 characters and numRows up to 1000.

## Approach

The solution simulates the zigzag pattern by maintaining a vector of strings, one for each row. It iterates through the input string character by character, appending each character to the appropriate row string. A direction variable toggles between moving down (+1) and up (-1) through the rows, changing direction whenever the current row index reaches the top (0) or bottom (numRows-1) boundary. After all characters are distributed into their respective rows, the solution concatenates all row strings in order to produce the final result. An edge case handler returns the original string immediately when numRows is 1.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-07 03:19 UTC
- Runtime: 4 ms
- Memory: 13.7 MB
- Language: C++
