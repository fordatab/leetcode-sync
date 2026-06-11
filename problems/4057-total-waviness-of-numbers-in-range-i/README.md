# Total Waviness of Numbers in Range I

**Difficulty:** Medium
**Tags:** array, iteration, digit-manipulation, brute-force

## Problem

Given an inclusive range of integers [num1, num2], compute the total waviness across all numbers. A number's waviness is the count of its peaks (digits strictly greater than both neighbors) and valleys (digits strictly less than both neighbors). First and last digits can never be peaks or valleys, and numbers with fewer than three digits have waviness zero.

## Approach

The solution uses a brute-force iteration approach. For each number in the range [num1, num2], it converts the number to a vector of digits using `toVec()`, which extracts digits via modulo-10 operations and reverses them to maintain correct order. Then `countPnV()` scans through the middle positions of the digit vector, checking each digit against its immediate neighbors to determine if it forms a peak (strictly greater than both neighbors) or valley (strictly less than both neighbors), incrementing a counter for each match. The main function accumulates these counts across all numbers in the range and returns the sum.

## Complexity

- **Time:** O(n * d)
- **Space:** O(d)

## Stats

- Submitted: 2026-06-11 02:02 UTC
- Runtime: 439 ms
- Memory: 119.2 MB
- Language: C++
