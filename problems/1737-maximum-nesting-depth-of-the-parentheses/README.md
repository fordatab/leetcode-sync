# Maximum Nesting Depth of the Parentheses

**Difficulty:** Easy
**Tags:** string, stack, counting

## Problem

Given a string containing digits, operators, and parentheses (guaranteed to be a valid parentheses string), determine the maximum nesting depth of the parentheses. The nesting depth is the deepest level at which parentheses are nested within each other. The string length is between 1 and 100 characters.

## Approach

The solution uses a counter-based approach to track parenthesis depth. It iterates through each character in the string once, maintaining a running count of open brackets. When an opening parenthesis is encountered, the counter increments; when a closing parenthesis is found, it decrements. Throughout the traversal, the solution tracks the maximum value this counter reaches, which represents the deepest nesting level. This works because at any point in a valid parentheses string, the count of unmatched opening brackets equals the current nesting depth.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-04-22 04:58 UTC
- Runtime: 0 ms
- Memory: 8.3 MB
- Language: C++
