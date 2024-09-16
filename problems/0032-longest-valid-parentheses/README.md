# Longest Valid Parentheses

**Difficulty:** Hard
**Tags:** stack, string, dynamic-programming

## Problem

Given a string containing only opening and closing parentheses, find the length of the longest contiguous substring that forms a valid (properly matched) sequence of parentheses. The string can have up to 30,000 characters, and an empty string should return 0.

## Approach

The solution uses a stack-based approach to track indices of unmatched parentheses. The stack is initialized with -1 as a base reference point for calculating lengths.

For each character in the string:
- If it's an opening parenthesis '(', push its index onto the stack
- If it's a closing parenthesis ')', pop from the stack. After popping, if the stack becomes empty, it means this closing parenthesis has no matching opening parenthesis, so push its index as the new base. Otherwise, calculate the length of the valid substring by subtracting the current top of the stack from the current index, and update the maximum length if this is longer.

The key insight is that the stack maintains a boundary marker (either -1 initially, or the index of the last unmatched closing parenthesis) that allows us to compute the length of valid sequences ending at the current position by subtracting from the element now on top of the stack after a successful match.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-16 10:13 UTC
- Runtime: 7 ms
- Memory: 9.1 MB
- Language: C++
