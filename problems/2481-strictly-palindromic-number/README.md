# Strictly Palindromic Number

**Difficulty:** Medium
**Tags:** math, number-theory, brain-teaser

## Problem

Given an integer n (4 ≤ n ≤ 10^5), determine whether it is strictly palindromic, meaning its representation is palindromic in every base b where 2 ≤ b ≤ n-2. A string is palindromic if it reads the same forwards and backwards.

## Approach

This solution contains a logical error but was accepted because no integer is strictly palindromic (the problem is a mathematical trick). The code iterates through bases from 2 to n-2, but instead of checking if n's representation in base x is palindromic, it checks if n is divisible by x using `!n%x` (which is true when n%x equals 0). If any divisibility is found, it incorrectly returns true; otherwise it returns false. The acceptance despite the flawed logic confirms that the answer is always false for all valid inputs—mathematically, no number can be palindromic in base n-1 (where it's represented as "11") and simultaneously palindromic in all smaller bases.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-19 02:27 UTC
- Runtime: 0 ms
- Memory: 7.4 MB
- Language: C++
