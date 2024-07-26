# Spiral Matrix IV

**Difficulty:** Medium
**Tags:** matrix, linked-list, simulation, spiral-traversal

## Problem

Given dimensions m×n for a matrix and a singly-linked list, fill the matrix in clockwise spiral order starting from the top-left corner with values from the linked list. Any remaining unfilled cells should contain -1. The linked list may have fewer than m×n nodes, and matrix dimensions can be as large as 10^5 (though their product is capped at 10^5).

## Approach

The solution initializes an m×n matrix filled with -1, then traverses it in spiral order while consuming the linked list. It maintains a direction vector `dir` as a pair (row_delta, col_delta) that starts at (0, 1) for moving right. At each step, it places the current list node's value at position (i, j), then checks if continuing in the current direction would go out of bounds or hit an already-filled cell. If so, it rotates the direction 90 degrees clockwise using the helper function `s()` (right→down→left→up→right). The rotation logic transforms the direction pair: (0,1)→(1,0)→(0,-1)→(-1,0)→(0,1). After determining the valid direction, it updates the position and advances to the next list node. This continues until the linked list is exhausted.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-07-26 22:37 UTC
- Runtime: 172 ms
- Memory: 130.6 MB
- Language: C++
