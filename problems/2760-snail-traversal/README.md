# Snail Traversal

**Difficulty:** Medium
**Tags:** array, matrix, simulation, traversal

## Problem

Transform a 1D array into a 2D array following a snail traversal pattern, where elements fill columns alternately from top-to-bottom and bottom-to-top. The method should return an empty array if the product of rowsCount and colsCount doesn't equal the array length. The transformation requires placing consecutive array elements down the first column, then up the second column, down the third, and so on.

## Approach

The solution adds a `snail` method to the Array prototype that first validates the dimensions match the array length. It then creates a result array with `numRows` empty sub-arrays.

The core logic uses nested loops: the outer loop iterates through columns (`row` variable, despite the name), and the inner loop iterates through rows (`col` variable). For each element, it calculates the source index as `row * numRows + col`.

The key insight is using a bitwise AND (`row & 1`) to determine if the current column index is odd or even. For even columns (bit is 0), elements are pushed to rows in ascending order (`col`). For odd columns (bit is 1), elements are pushed to rows in descending order (`numRows - col - 1`), creating the alternating up-down pattern.

Each `push` appends the element to the appropriate row's array, building the 2D structure column by column with the correct directional filling.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 21:53 UTC
- Runtime: 168 ms
- Memory: 63.7 MB
- Language: JavaScript
