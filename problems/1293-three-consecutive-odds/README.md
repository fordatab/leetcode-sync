# Three Consecutive Odds

**Difficulty:** Easy
**Tags:** array, counting, linear-scan

## Problem

Given an integer array of length 1 to 1000 with values between 1 and 1000, determine whether the array contains three consecutive odd numbers. Return true if such a sequence exists, false otherwise.

## Approach

The solution uses a single-pass scan with a counter to track consecutive odd numbers. It iterates through the array and maintains an `odds` counter that increments when an odd number is encountered (checked via modulo 2) and resets to zero when an even number is found. At each step, if the counter reaches 3, the function immediately returns true. If the entire array is processed without finding three consecutive odds, it returns false.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-26 02:11 UTC
- Runtime: 3 ms
- Memory: 10.8 MB
- Language: C++
