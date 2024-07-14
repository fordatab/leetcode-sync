# Find Minimum Operations to Make All Elements Divisible by Three

**Difficulty:** Easy
**Tags:** math, greedy, modulo-arithmetic

## Problem

Given an integer array, determine the minimum number of add-or-subtract-1 operations needed to make every element divisible by 3. The array has at most 50 elements, each between 1 and 50.

## Approach

The solution iterates through each element and checks its remainder when divided by 3 using the modulo operator. For each element:

- If the remainder is 0, the element is already divisible by 3, so no operation is needed.
- If the remainder is 1, one subtraction operation brings it to the nearest multiple of 3.
- If the remainder is 2, one addition operation brings it to the next multiple of 3.

A switch statement handles these three cases, incrementing a counter whenever the remainder is non-zero. The total count is returned as the minimum number of operations.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:19 UTC
- Runtime: 8 ms
- Memory: 22.7 MB
- Language: C++
