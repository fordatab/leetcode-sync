# Power of Two

**Difficulty:** Easy
**Tags:** bit-manipulation, math, iteration

## Problem

Given an integer n, determine whether it represents a power of two (i.e., whether there exists some integer x such that n equals 2 raised to the x). The input can range from -2^31 to 2^31 - 1, including negative numbers and zero which are never powers of two.

## Approach

The solution uses an iterative division approach. First, it handles the base case by returning false for any number less than 1, since negative numbers and zero cannot be powers of two. Then it enters a loop that repeatedly divides n by 2 as long as n is greater than 1. During each iteration, it checks if n is odd (using the modulo operator); if so, it immediately returns false because a power of two divided by 2 must always be even until we reach 1. After the loop exits, the code checks if n is zero (which would indicate an unexpected state) and returns false if so, otherwise returns true. The algorithm essentially verifies that n can be repeatedly halved without remainder until reaching 1.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-13 03:48 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
