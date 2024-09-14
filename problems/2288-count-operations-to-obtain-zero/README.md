# Count Operations to Obtain Zero

**Difficulty:** Easy
**Tags:** simulation, math, iteration

## Problem

Given two non-negative integers, repeatedly subtract the smaller from the larger (or either from the other if equal) until one becomes zero. Return the total count of such subtraction operations performed. The integers can be as large as 100,000.

## Approach

The solution uses a straightforward simulation approach. It maintains a counter initialized to zero and enters a loop that continues while both numbers are non-zero. In each iteration, it checks which number is larger or if they're equal: if `num1` is greater than or equal to `num2`, it subtracts `num2` from `num1`; otherwise, it subtracts `num1` from `num2`. After each subtraction, the operation counter is incremented. The loop terminates when either number reaches zero, and the counter is returned as the result.

## Complexity

- **Time:** O(max(num1, num2))
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 03:53 UTC
- Runtime: 4 ms
- Memory: 7.6 MB
- Language: C++
