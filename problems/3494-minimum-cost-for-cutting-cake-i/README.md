# Minimum Cost for Cutting Cake I

**Difficulty:** Medium
**Tags:** greedy, divide-and-conquer, recursion, optimization

## Problem

Given an m×n cake, find the minimum total cost to cut it into 1×1 pieces. Each horizontal cut i has a cost horizontalCut[i] and each vertical cut j has a cost verticalCut[j]. When a piece is cut, it splits into two pieces, and subsequent cuts on those pieces still use the original costs from the arrays. The goal is to determine the optimal order of cuts to minimize the total cost.

## Approach

The solution uses a greedy recursive approach with divide-and-conquer. At each step, it examines all remaining horizontal and vertical cuts in the current sub-rectangle (bounded by m_f to m_t horizontally and n_f to n_t vertically) and selects the cut with the maximum cost. This greedy choice is optimal because making expensive cuts early, when they affect fewer pieces, is cheaper than making them later when the cake is already divided into many pieces.

The recursion has three base cases: if the piece is already 1×1, return 0; if only one dimension needs cutting, sum all remaining cuts in that dimension. For the recursive case, the algorithm finds the most expensive available cut (either horizontal or vertical), makes that cut, and recursively solves for the two resulting sub-rectangles.

The key insight is that cutting along an expensive line early minimizes how many times that cost is paid, since each subsequent perpendicular cut would multiply the cost of having to make that expensive cut across multiple pieces.

## Complexity

- **Time:** O(m * n * (m + n))
- **Space:** O(m * n)

## Stats

- Submitted: 2024-07-14 03:37 UTC
- Runtime: 7 ms
- Memory: 34.8 MB
- Language: C++
