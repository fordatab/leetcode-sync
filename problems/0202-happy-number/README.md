# Happy Number

**Difficulty:** Easy
**Tags:** hash-table, math, simulation, cycle-detection

## Problem

Determine whether a positive integer is a "happy number" by repeatedly replacing it with the sum of the squares of its digits. A number is happy if this process eventually reaches 1; otherwise, it will cycle indefinitely without reaching 1. The input is constrained to integers from 1 to 2^31 - 1.

## Approach

The solution uses a hash set to detect cycles in the digit-square-sum sequence. It repeatedly extracts each digit of the current number by taking modulo 10, squares it, and accumulates the sum. Once all digits are processed, the current number is replaced by this sum.

A hash set tracks all previously seen numbers. Before processing each number, the code checks whether it has been encountered before—if so, a cycle is detected and the number cannot be happy, so it returns false. If the process reaches 1 before any cycle is detected, the number is happy and the function returns true.

The inner while loop extracts digits one by one using modulo and integer division, computing the sum of their squares. The outer loop continues until either 1 is reached (happy) or a previously seen value reappears (not happy).

## Complexity

- **Time:** O(log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-13 04:09 UTC
- Runtime: 0 ms
- Memory: 8.3 MB
- Language: C++
