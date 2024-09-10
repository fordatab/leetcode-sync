# Sum of Squares of Special Elements 

**Difficulty:** Easy
**Tags:** array, math, simulation

## Problem

Given a 1-indexed integer array of length n, find all elements at positions i where i divides n evenly (n % i == 0), and return the sum of their squares. The array has length between 1 and 50, with element values also between 1 and 50.

## Approach

The solution iterates through the array using 0-based indexing and checks if each position (adjusted to 1-based by adding 1) is a divisor of the array length n. For each position x where (x+1) divides n evenly, it squares the element at that position and adds it to a running sum. This direct iteration approach examines every index once, checking the divisibility condition and accumulating the squared values of qualifying elements.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 07:32 UTC
- Runtime: 8 ms
- Memory: 39.7 MB
- Language: C++
