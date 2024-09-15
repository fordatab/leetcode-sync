# Basic Calculator

**Difficulty:** Hard
**Tags:** stack, string-parsing, expression-evaluation, math

## Problem

Evaluate a mathematical expression string containing non-negative integers, addition, subtraction, and parentheses, returning the numeric result. The expression can be up to 300,000 characters long and may contain spaces. Unary minus is allowed (e.g., "-1" or "-(2+3)"), but unary plus is not.

## Approach

The solution uses a stack-based approach to handle nested parentheses and sign propagation. It maintains a stack of sign multipliers (initialized with 1) where each level represents the cumulative sign effect at that depth of parentheses. As it scans left to right, it builds multi-digit numbers digit by digit. When encountering a non-digit character, it adds the accumulated number (multiplied by the current sign and stack top) to the running total. For '+' and '-', it updates the `isPositive` flag. When encountering '(', it pushes a new multiplier onto the stack (the product of the current sign and the previous stack top), effectively propagating the sign context into the nested expression, then resets the sign to positive. For ')', it pops the stack to exit that nesting level. After the loop, it adds any remaining number to get the final result.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-15 03:58 UTC
- Runtime: 6 ms
- Memory: 10.1 MB
- Language: C++
