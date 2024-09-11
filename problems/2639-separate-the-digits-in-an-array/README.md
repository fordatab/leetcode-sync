# Separate the Digits in an Array

**Difficulty:** Easy
**Tags:** array, string, simulation

## Problem

Given an array of positive integers (each up to 10^5), produce a new array containing all the individual digits of each number in sequence. The digits within each number must maintain their order, and the numbers themselves must be processed left-to-right through the input array. For instance, [13, 25] becomes [1, 3, 2, 5].

## Approach

The solution iterates through each integer in the input array and converts it to a string representation using `to_string()`. For each resulting string, it walks through every character, converts each character back to its numeric digit value by subtracting the ASCII code of '0', and appends that digit to the output vector. This string-based approach naturally handles multi-digit numbers by processing digits in left-to-right order without requiring arithmetic operations like division or modulo to extract individual digits.

## Complexity

- **Time:** O(n * d)
- **Space:** O(n * d)

## Stats

- Submitted: 2024-09-11 01:51 UTC
- Runtime: 5 ms
- Memory: 14.7 MB
- Language: C++
