# Nested List Weight Sum

**Difficulty:** Medium
**Tags:** stack, depth-first-search, recursion-simulation, nested-structures

## Problem

Given a nested list where elements can be integers or lists containing more integers or lists, compute a weighted sum where each integer is multiplied by its nesting depth (starting at 1 for the outermost level). The input has at most 50 elements, integer values range from -100 to 100, and maximum nesting depth is 50.

## Approach

The solution uses an iterative depth-first traversal with an explicit stack. For each element in the input list, it pushes the element paired with its depth (initially 1) onto the stack. While processing:

- If the current element is an integer, multiply it by its depth and add to the running total
- If the current element is a list, push all its children onto the stack with depth incremented by 1

This continues until the stack is empty, processing each element at the appropriate depth level. The stack stores pairs of `(NestedInteger, depth)` to track both the element and its current nesting level as it traverses the structure.

## Complexity

- **Time:** O(n)
- **Space:** O(d)

## Stats

- Submitted: 2026-05-28 07:53 UTC
- Runtime: 0 ms
- Memory: 13.6 MB
- Language: C++
