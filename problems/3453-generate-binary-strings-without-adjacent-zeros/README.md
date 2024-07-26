# Generate Binary Strings Without Adjacent Zeros

**Difficulty:** Medium
**Tags:** backtracking, recursion, string, depth-first-search

## Problem

Given a positive integer n (1 ≤ n ≤ 18), generate all binary strings of length n where no two consecutive characters are both '0'. In other words, every substring of length 2 must contain at least one '1'. Return all such valid strings in any order.

## Approach

The solution uses recursive backtracking (depth-first search) to build all valid binary strings character by character. It maintains a string `s` that is built up during recursion and added to the result when it reaches length n.

The algorithm has two main cases: if the string is empty, it can start with either '0' or '1'. For non-empty strings, it checks the last character: if it's '1', the next character can be either '0' or '1'; if it's '0', the next character must be '1' (to avoid adjacent zeros). The recursive function decrements n with each character added and backtracks by popping the last character after exploring each branch.

The base case occurs when n reaches 0, at which point the current string is a complete valid string of the original length and is added to the output vector. The backtracking is implemented by pushing a character, recursing, then popping it before trying the next option.

## Complexity

- **Time:** O(2^n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-26 05:04 UTC
- Runtime: 7 ms
- Memory: 20.4 MB
- Language: C++
