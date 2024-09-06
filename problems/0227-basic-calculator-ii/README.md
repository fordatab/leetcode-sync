# Basic Calculator II

**Difficulty:** Medium
**Tags:** stack, string-parsing, math, expression-evaluation

## Problem

Given a string containing an arithmetic expression with integers and the operators +, -, *, /, evaluate the expression respecting standard operator precedence (multiplication and division before addition and subtraction). The string may contain spaces, division truncates toward zero, and all intermediate results fit in a 32-bit signed integer. The expression length can be up to 300,000 characters.

## Approach

The solution uses a stack to parse and evaluate the expression in a single pass. As each digit is encountered, it's accumulated into the top stack value by multiplying by 10 and adding the digit. When an operator is found, the code checks the previous operator to handle multiplication and division immediately (collapsing the stack by popping the operator marker and applying the operation). Operator markers are encoded as negative integers (-1 for *, -2 for /, -3 for +, -4 for -), which are pushed onto the stack along with a new 0 to start accumulating the next number. Subtraction is handled by negating the operand. After processing all characters, any pending multiplication or division is applied, then the remaining stack (containing only addition operations at this point) is collapsed by summing all values. This approach effectively handles operator precedence by eagerly evaluating higher-precedence operations while deferring lower-precedence ones.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-06 05:20 UTC
- Runtime: 37 ms
- Memory: 15.7 MB
- Language: C++
