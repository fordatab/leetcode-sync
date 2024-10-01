# Valid Perfect Square

**Difficulty:** Easy
**Tags:** binary-search, math

## Problem

Given a positive integer up to 2^31 - 1, determine whether it is a perfect square (the product of an integer with itself) without using built-in square root functions. Return true if the number is a perfect square, false otherwise.

## Approach

The solution uses binary search to find if there exists an integer whose square equals the input number. The search space is bounded between 1 and 46340, since 46340^2 is approximately 2^31 - 1, the maximum possible input value.

At each iteration, the code calculates the midpoint and checks if its square equals the target number. If mid * mid equals num, it immediately returns true. If mid * mid is less than num, the search continues in the upper half by moving the left pointer. If mid * mid is greater than num, the search continues in the lower half by moving the right pointer.

The binary search terminates when the pointers cross (l > r), at which point no perfect square root was found and the function returns false.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-10-01 18:23 UTC
- Runtime: 2 ms
- Memory: 7.3 MB
- Language: C++
