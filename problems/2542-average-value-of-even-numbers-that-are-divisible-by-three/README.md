# Average Value of Even Numbers That Are Divisible by Three

**Difficulty:** Easy
**Tags:** array, math, iteration

## Problem

Given an array of positive integers, compute the average of all numbers that are both even and divisible by 3, rounding down to the nearest integer. If no such numbers exist, return 0. The array can contain up to 1000 elements, each ranging from 1 to 1000.

## Approach

The solution iterates through the input array once, checking each number for divisibility by 6 (since a number divisible by both 2 and 3 is divisible by 6). It maintains a running sum (`total`) of qualifying numbers and a counter (`i`) tracking how many such numbers have been found.

For each element, the modulo operator checks if `n % 6 == 0`. When this condition holds, the number is added to the total and the counter is incremented.

After processing all elements, if the total is zero (meaning no qualifying numbers were found), the function returns 0. Otherwise, it returns the integer division of the total by the count, which automatically rounds down as required.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-05 09:37 UTC
- Runtime: 0 ms
- Memory: 17.4 MB
- Language: C++
