# Count Integers With Even Digit Sum

**Difficulty:** Easy
**Tags:** math, simulation, brute-force

## Problem

Given a positive integer num (1 ≤ num ≤ 1000), count how many integers from 1 to num (inclusive) have an even digit sum. The digit sum is calculated by adding all digits of a number together.

## Approach

The solution uses a brute-force approach that iterates through every integer from 1 to num. For each number, it computes the digit sum by repeatedly extracting the last digit (using modulo 10) and dividing by 10 until no digits remain. The extracted digits are accumulated in a sum variable. After computing the digit sum for a number, it checks if the sum is even by testing if `sum % 2 == 0`. If true, it increments the output counter. This process continues for all numbers in the range, and the final count is returned.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-03 22:07 UTC
- Runtime: 3 ms
- Memory: 7.4 MB
- Language: C++
