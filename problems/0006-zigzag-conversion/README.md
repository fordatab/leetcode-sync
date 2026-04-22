# Zigzag Conversion

**Difficulty:** Medium
**Tags:** string, simulation, array

## Problem

Given a string and a number of rows, arrange the characters in a zigzag pattern vertically across the specified number of rows, then read the result row by row to produce a new string. For example, with 3 rows, characters flow down then diagonally up repeatedly. The string length can be up to 1000 characters, and the number of rows can be up to 1000.

## Approach

The solution simulates the zigzag pattern by maintaining a vector of strings, one for each row. It iterates through the input string character by character, appending each character to the appropriate row string. A direction variable tracks whether we're moving down or up through the rows: when we reach the top row (index 0) or bottom row (index numRows-1), the direction reverses. The current row index `j` is incremented when moving down (dir=1) and decremented when moving up (dir=-1). After processing all characters, the solution concatenates all row strings in order to produce the final output. An early return handles the edge case where numRows is 1, avoiding unnecessary processing.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-22 05:00 UTC
- Runtime: 2 ms
- Memory: 14.3 MB
- Language: C++
