# Bulb Switcher

**Difficulty:** Medium
**Tags:** math, number-theory, perfect-squares, brain-teaser

## Problem

Given n bulbs initially off, perform n rounds of toggling where in round i you toggle every i-th bulb (round 1 toggles all, round 2 toggles every 2nd, etc.). Determine how many bulbs remain on after all rounds. The constraint allows n up to 10^9, requiring an efficient mathematical solution rather than simulation.

## Approach

The solution recognizes that a bulb at position k gets toggled once for each divisor of k. A bulb ends up on if it's toggled an odd number of times, which happens only when k has an odd number of divisors. Numbers have an odd number of divisors only when they are perfect squares (since divisors come in pairs except when a number is a perfect square, where one divisor pairs with itself). Therefore, the number of bulbs that remain on equals the count of perfect squares from 1 to n, which is simply floor(sqrt(n)). The solution directly computes and returns the integer square root of n.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-25 07:12 UTC
- Runtime: 2 ms
- Memory: 7.4 MB
- Language: C++
