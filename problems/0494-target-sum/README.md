# Target Sum

**Difficulty:** Medium
**Tags:** dynamic-programming, memoization, recursion, hash-table, backtracking

## Problem

Given an array of non-negative integers and a target value, determine how many ways you can assign plus or minus signs to each array element such that the resulting expression evaluates to the target. The array has at most 20 elements, each with a value up to 1000, and the target ranges from -1000 to 1000.

## Approach

The solution uses memoized recursion (top-down dynamic programming) to explore all possible sign assignments. It recursively processes each element, branching into two possibilities: adding or subtracting the current number from the running total. The memoization key is cleverly constructed by bit-packing the current index (left-shifted 32 bits) and the current sum into a single long integer, allowing efficient caching of subproblem results in an unordered map. When reaching the end of the array, it checks if the accumulated sum matches the target and returns 1 for success or 0 for failure. The function combines results from both branches (addition and subtraction) to count all valid expressions.

## Complexity

- **Time:** O(n * s)
- **Space:** O(n * s)

## Stats

- Submitted: 2024-08-29 01:19 UTC
- Runtime: 164 ms
- Memory: 64.7 MB
- Language: C++
