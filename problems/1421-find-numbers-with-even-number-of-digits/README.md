# Find Numbers with Even Number of Digits

**Difficulty:** Easy
**Tags:** array, math, counting

## Problem

Given an array of positive integers (each between 1 and 100,000), count how many numbers have an even number of digits. The array can contain up to 500 elements.

## Approach

The solution iterates through each number in the input array. For each number, it counts the digits by repeatedly dividing by 10 until the number becomes zero, incrementing a digit counter with each division. After counting the digits for a number, it checks if the count is even using the modulo operator. If the digit count is even, it increments the output counter. Finally, it returns the total count of numbers with an even number of digits.

## Complexity

- **Time:** O(n * d)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-11 02:31 UTC
- Runtime: 4 ms
- Memory: 12.4 MB
- Language: C++
