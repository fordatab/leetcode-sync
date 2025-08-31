# Four Divisors

**Difficulty:** Medium
**Tags:** math, number-theory, divisors, iteration

## Problem

Given an array of integers, identify which numbers have exactly four divisors. For each such number, sum all its divisors, then return the total of these sums across all qualifying numbers. The array can contain up to 10,000 elements, with each element ranging from 1 to 100,000.

## Approach

The solution iterates through each number in the input array. For each number, it finds all divisors by checking integers from 1 up to the square root of the number. When a divisor `x` is found (when `a % x == 0`), it identifies both `x` and its complement `y = a / x`. If `x` equals `y` (meaning the number is a perfect square), it counts one divisor; otherwise, it counts two divisors and adds both to the running sum. The algorithm includes an early termination optimization: if the divisor count exceeds 4, it breaks out of the inner loop since the number can't qualify. After examining all potential divisors, if exactly 4 divisors were found, their sum is added to the final result.

## Complexity

- **Time:** O(n * sqrt(m))
- **Space:** O(1)

## Stats

- Submitted: 2025-08-31 08:23 UTC
- Runtime: 15 ms
- Memory: 16.3 MB
- Language: C++
