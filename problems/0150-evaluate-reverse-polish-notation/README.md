# Evaluate Reverse Polish Notation

**Difficulty:** Medium
**Tags:** stack, string, arithmetic-expression, postfix-notation

## Problem

Given an array of strings representing an arithmetic expression in Reverse Polish Notation (postfix notation), compute and return the integer result. The array contains integers in the range [-200, 200] and the four basic operators (+, -, *, /). Division truncates toward zero, and all intermediate results fit in a 32-bit integer. The input is guaranteed to be a valid RPN expression.

## Approach

The solution uses a stack-based evaluation approach that naturally fits RPN semantics. It iterates through each token in the array:

- If the token is an operator (+, -, *, /), it pops two operands from the stack (the second pop is the left operand, the first pop is the right operand), applies the operator, and pushes the result back onto the stack.
- If the token is a number (checked by eliminating operators), it converts the string to an integer and pushes it onto the stack.
- A switch statement handles the four arithmetic operations based on the first character of the operator string.
- After processing all tokens, the final result remains as the only element on the stack, which is returned.

This implementation correctly maintains operand order by popping the right operand first, then the left operand, ensuring expressions like "5 3 -" evaluate to 2 (not -2).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-28 05:45 UTC
- Runtime: 12 ms
- Memory: 15.3 MB
- Language: C++
