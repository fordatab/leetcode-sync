# Two Sum

**Difficulty:** Easy
**Tags:** array, brute-force, nested-loops

## Problem

Given an array of integers and a target value, find the indices of two distinct elements that sum to the target. The input is guaranteed to have exactly one valid pair, and the array contains between 2 and 10,000 elements with values ranging from -10^9 to 10^9.

## Approach

The solution uses a brute-force nested loop approach. The outer loop iterates through each element using index `x`, while the inner loop iterates through all elements using index `y`. For each pair of indices, it checks whether their corresponding values sum to the target and ensures the indices are different (x != y). When a valid pair is found, it allocates memory for a two-element array, stores the indices, and returns them immediately. This checks all possible pairs exhaustively until finding the answer.

## Complexity

- **Time:** O(n^2)
- **Space:** O(1)

## Stats

- Submitted: 2023-07-29 23:54 UTC
- Runtime: 150 ms
- Memory: 6.3 MB
- Language: C
