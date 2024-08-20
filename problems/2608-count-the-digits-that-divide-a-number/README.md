# Count the Digits That Divide a Number

**Difficulty:** Easy
**Tags:** math, digit-manipulation, iteration

## Problem

Given a positive integer up to 10^9 that contains no zeros, count how many of its individual digits evenly divide the original number. Each occurrence of a digit is counted separately, so if a digit appears multiple times and divides the number, it contributes to the count each time it appears.

## Approach

The solution iterates through each digit of the number by repeatedly extracting the last digit using the modulo operator (`n % 10`) and then removing it via integer division (`n /= 10`). For each extracted digit, it checks whether the original number is divisible by that digit using the modulo operation (`num % (n%10) == 0`). If the remainder is zero, a counter is incremented. The process continues until all digits have been processed (when `n` becomes zero), and the final count is returned.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-20 05:49 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
