# Single Number

**Difficulty:** Easy
**Tags:** bit-manipulation, array, xor

## Problem

Given an array of integers where every element appears exactly twice except for one element that appears once, find and return the unique element. The solution must run in linear time and use constant extra space, with array lengths up to 30,000 and values ranging from -30,000 to 30,000.

## Approach

This solution leverages the XOR bitwise operation's mathematical properties to identify the unique element. The code initializes a variable `j` with the first array element, then iterates through the remaining elements, applying XOR to accumulate each value.

The key insight is that XOR has two critical properties: `a ^ a = 0` (any number XORed with itself equals zero) and `a ^ 0 = a` (any number XORed with zero equals itself). Additionally, XOR is both commutative and associative, meaning the order of operations doesn't matter.

As the loop processes all elements, each number appearing twice will XOR to zero, effectively canceling out. The single number that appears only once will remain, since it XORs with zero (the cumulative result of all paired numbers). After processing the entire array, `j` contains the unique element, which is returned.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-19 01:55 UTC
- Runtime: 7 ms
- Memory: 19.6 MB
- Language: C++
