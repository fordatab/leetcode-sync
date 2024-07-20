# Sum of All Subset XOR Totals

**Difficulty:** Easy
**Tags:** backtracking, bit-manipulation, subsets, recursion

## Problem

Given an array of integers, compute the XOR of each possible subset (including the empty subset), then return the sum of all these XOR values. The array has at most 12 elements with values up to 20, making exhaustive enumeration feasible.

## Approach

The solution generates all possible subsets using backtracking (depth-first search). For each index in the input array, the `dfs` function makes two recursive choices: include the current element in the subset or exclude it. Once all 2^n subsets are collected in a vector, the code iterates through each subset, computes its XOR total by iterating through its elements and applying the XOR operation cumulatively, and adds this XOR value to a running sum. The empty subset contributes 0 to the sum.

## Complexity

- **Time:** O(n * 2^n)
- **Space:** O(n * 2^n)

## Stats

- Submitted: 2024-07-20 05:57 UTC
- Runtime: 40 ms
- Memory: 25.4 MB
- Language: C++
