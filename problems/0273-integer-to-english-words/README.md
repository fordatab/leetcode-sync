# Integer to English Words

**Difficulty:** Hard
**Tags:** string, math, recursion, number-conversion

## Problem

Given a non-negative integer up to 2^31 - 1, convert it into its English word representation. The solution must handle numbers from zero up to over two billion, properly formatting groups of thousands, millions, and billions with appropriate spacing and capitalization.

## Approach

The solution processes the number in groups of three digits (thousands, millions, billions). It maintains lookup tables for ones (0-9), teens (10-19), and tens (20-90). The main function `numberToWords` iteratively extracts the last three digits using modulo 1000, converts each chunk via the `convert` helper function, and appends the appropriate scale unit (Thousand, Million, Billion). The `convert` function handles a three-digit group by separately processing hundreds, tens, and ones places. For the tens place, it special-cases 10-19 using the "ten" array, otherwise uses the "tens" array for multiples of ten. Each converted chunk is concatenated with proper spacing, building the result from right to left (least significant to most significant groups). The edge case of zero is handled explicitly at the start.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2025-12-03 10:08 UTC
- Runtime: 2 ms
- Memory: 11.2 MB
- Language: C++
