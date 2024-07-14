# Final Value of Variable After Performing Operations

**Difficulty:** Easy
**Tags:** array, string, simulation

## Problem

Given an array of operation strings where each operation is either an increment (++X or X++) or decrement (--X or X--), determine the final value of a variable X that starts at 0 after applying all operations in sequence. The array length is at most 100, and each operation modifies X by exactly 1.

## Approach

The solution iterates through each operation string in the input array exactly once. For each operation, it checks whether the string equals one of the two increment variants ("++X" or "X++"). If so, it increments the variable `x` by 1; otherwise, it decrements `x` by 1. Since prefix and postfix operations produce the same net effect when we only care about the final value (not intermediate expressions), the code treats both increment forms identically and both decrement forms identically. After processing all operations, it returns the accumulated value of `x`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:21 UTC
- Runtime: 4 ms
- Memory: 18.1 MB
- Language: C++
