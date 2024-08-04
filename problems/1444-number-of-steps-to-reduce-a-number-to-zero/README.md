# Number of Steps to Reduce a Number to Zero

**Difficulty:** Easy
**Tags:** bit-manipulation, simulation, math

## Problem

Given a non-negative integer, count how many operations are needed to reduce it to zero. Each operation either divides the number by 2 if it's even, or subtracts 1 if it's odd. The input is constrained to the range [0, 10^6].

## Approach

The solution uses a straightforward simulation approach with bitwise operations. It maintains a counter and loops while the number is non-zero. For even numbers, it performs a right bit shift (equivalent to dividing by 2). For odd numbers, it uses a bitwise AND with a mask that clears the least significant bit (equivalent to subtracting 1). Each iteration increments the step counter. The loop terminates when the number reaches zero, and the total count is returned.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-04 08:16 UTC
- Runtime: 0 ms
- Memory: 7.4 MB
- Language: C++
