# Find if Digit Game Can Be Won

**Difficulty:** Easy
**Tags:** array, math, greedy, simulation

## Problem

Given an array of positive integers (1-99), Alice chooses either all single-digit numbers (1-9) or all double-digit numbers (10-99), while Bob gets the remaining numbers. Determine if Alice can win by having a strictly greater sum than Bob for at least one of her two possible choices.

## Approach

The solution partitions the input array into two groups: single-digit numbers (values less than 10) and double-digit numbers (values 10 or greater). It accumulates the sum of single-digit numbers in variable `s` and double-digit numbers in variable `t` by iterating through the array once and checking each number with the condition `x / 10 == 0` (integer division). 

The key insight is that if Alice picks single-digit numbers, her sum is `s` and Bob's sum is `t`. If Alice picks double-digit numbers, her sum is `t` and Bob's sum is `s`. Alice wins if either `s > t` or `t > s`, which is equivalent to `s != t`. The solution returns true if the two sums are unequal, meaning Alice has a winning strategy.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-28 02:49 UTC
- Runtime: 12 ms
- Memory: 28.2 MB
- Language: C++
