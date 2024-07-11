# Plus One

**Difficulty:** Easy
**Tags:** array, math, simulation

## Problem

Given an array representing the digits of a non-negative integer in big-endian order (most significant digit first), increment the represented number by one and return the resulting digit array. The array can have up to 100 digits, and no leading zeros are present in the input.

## Approach

The solution simulates manual addition starting from the least significant digit (rightmost). It increments the last digit by one, then propagates any carry leftward using a while loop. When a digit becomes 10 or greater, it's set to 0 and the carry moves to the next position left. If the carry reaches the most significant digit (index 0) and that digit also overflows, a new digit 1 is inserted at the beginning of the array to handle cases like 999 → 1000. The loop continues until no carry remains or the overflow at position 0 is handled.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 07:51 UTC
- Runtime: 0 ms
- Memory: 10.4 MB
- Language: C++
