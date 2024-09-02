# Difference Between Element Sum and Digit Sum of an Array

**Difficulty:** Easy
**Tags:** array, math, simulation

## Problem

Given an array of positive integers, calculate two sums: the element sum (sum of all array elements) and the digit sum (sum of all individual digits across all numbers). Return the absolute difference between these two sums. The array can contain up to 2000 elements, each with values between 1 and 2000.

## Approach

The solution processes each number in a single pass through the array. For each number, it first adds the entire number to an accumulator (`out`), contributing to the element sum. Then it enters a loop that repeatedly extracts the last digit using modulo 10 and subtracts it from the accumulator, effectively building the digit sum as a negative contribution. After processing all numbers, `out` contains the difference (element sum minus digit sum), and taking the absolute value gives the final answer. This approach cleverly combines both calculations in one variable by treating element sum as positive additions and digit sum as negative subtractions.

## Complexity

- **Time:** O(n * d)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-02 06:58 UTC
- Runtime: 8 ms
- Memory: 18.5 MB
- Language: C++
