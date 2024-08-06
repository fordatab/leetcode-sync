# Permutations II

**Difficulty:** Medium
**Tags:** backtracking, hash-table, recursion, permutation

## Problem

Given an array of integers that may contain duplicate values, generate all distinct permutations of the elements. The array length is at most 8, and each element ranges from -10 to 10. The output should contain each unique permutation exactly once, regardless of how many times a value appears in the input.

## Approach

This solution uses backtracking with a frequency map to avoid generating duplicate permutations. First, it counts the occurrence of each unique number in a hash map. During the recursive backtracking (function `d`), it iterates through the unique values in the map rather than positions in the array. For each unique value with remaining count greater than zero, it adds that value to the current permutation, decrements its count, recurses, then backtracks by removing the value and restoring the count. The base case triggers when the current permutation reaches the same length as the input array, at which point it's added to the result. By iterating over unique values and tracking their counts, this approach naturally prevents creating duplicate permutations that would arise from swapping identical elements.

## Complexity

- **Time:** O(n! / (c1! * c2! * ... * ck!))
- **Space:** O(n)

## Stats

- Submitted: 2024-08-06 09:58 UTC
- Runtime: 0 ms
- Memory: 11 MB
- Language: C++
