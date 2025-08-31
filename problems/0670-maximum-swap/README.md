# Maximum Swap

**Difficulty:** Medium
**Tags:** greedy, array, math, digit-manipulation

## Problem

Given a non-negative integer up to 10^8, you may swap at most two of its digits to maximize the resulting value. The goal is to return the largest number achievable through such a swap, or the original number if no beneficial swap exists.

## Approach

The solution converts the integer into a vector of its digits in left-to-right order. It first scans from left to right to find the longest non-increasing prefix, identifying where a potentially beneficial swap could start. Then it searches the remainder of the digit array (from position `i` onward) to find the maximum digit, keeping track of the rightmost occurrence of that maximum. Finally, it scans from the beginning again to find the first digit smaller than this maximum and swaps them. The modified digit vector is converted back to an integer and returned. This greedy approach ensures that the leftmost position gets the largest available digit from the right, maximizing the overall value.

## Complexity

- **Time:** O(d)
- **Space:** O(d)

## Stats

- Submitted: 2025-08-31 06:40 UTC
- Runtime: 0 ms
- Memory: 8 MB
- Language: C++
