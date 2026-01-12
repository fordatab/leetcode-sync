# Maximal Rectangle

**Difficulty:** Hard
**Tags:** stack, monotonic-stack, dynamic-programming, matrix, histogram

## Problem

Given a binary matrix of dimensions rows × cols containing only '0' and '1' characters, find the area of the largest rectangle that contains only '1's. The matrix can be up to 200×200 in size, and rectangles must be axis-aligned.

## Approach

The solution treats each row as a potential base for a rectangle and computes histogram heights extending upward from that row. For each row index, it builds a histogram where each column's height represents the number of consecutive '1's extending upward from the current row to row 0. It then applies the largest rectangle in histogram algorithm using a monotonic stack.

The histogram calculation uses a triple nested loop: for each row as a base, it iterates through each column and counts consecutive '1's going upward until hitting a '0' or the top of the matrix.

The `largestRectangleArea` helper uses a stack of (index, height) pairs to efficiently find the maximum rectangle in a histogram. It maintains a monotonically increasing stack and calculates rectangle areas when encountering a shorter bar by popping taller bars and computing their maximum extendable width.

After processing all histograms (one per row), the maximum area encountered across all row-based histograms is returned.

## Complexity

- **Time:** O(rows² × cols)
- **Space:** O(cols)

## Stats

- Submitted: 2026-01-12 22:27 UTC
- Runtime: 29 ms
- Memory: 20.3 MB
- Language: C++
