# Basic Calculator III

**Difficulty:** Hard
**Tags:** stack, expression-evaluation, string-parsing, operator-precedence

## Problem

Given a string representing a mathematical expression with non-negative integers and the four basic operators (+, -, *, /), plus parentheses for grouping, evaluate the expression and return the integer result. Division truncates toward zero. The expression is guaranteed to be valid, the string length is at most 10^4, and all intermediate results fit in a 32-bit signed integer.

## Approach

The solution uses a stack-based approach with operator precedence handling. It appends a sentinel character '@' to the string to force processing of the last number. As it scans each character:

- **Digits** are accumulated into a `curr` number.
- **Opening parentheses** push the current operator onto the stack and reset the operator to '+' for the new subexpression.
- **Operators and closing parentheses** trigger evaluation: if the previous operator was '*' or '/', it immediately applies that operation between the stack's top value and `curr`, pushing the result back. For '+' or '-', it pushes the (possibly negated) current number onto the stack.
- **Closing parentheses** sum all integers on the stack down to the last operator (which was pushed by the matching opening parenthesis), treating the sum as the new `curr` and restoring the saved operator.

Finally, it returns the sum of all values left on the stack, which represents the terms to be added together after all multiplications and divisions have been collapsed.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-08 08:23 UTC
- Runtime: 2 ms
- Memory: 17.9 MB
- Language: Python3
