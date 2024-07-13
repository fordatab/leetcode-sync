# Maximum Nesting Depth of the Parentheses

**Difficulty:** Easy
**Tags:** stack, string, parentheses

## Problem

Given a string containing digits, arithmetic operators, and parentheses that form a valid parentheses expression, determine the maximum nesting depth of the parentheses. The nesting depth is the greatest number of open parentheses that are simultaneously active at any point while traversing the string. The string length is at most 100 characters and is guaranteed to have balanced parentheses.

## Approach

The solution uses a stack to track open parentheses as it scans through the string character by character. When an opening parenthesis '(' is encountered, it's pushed onto the stack, and the current stack size is compared with the running maximum depth, updating the maximum if necessary. When a closing parenthesis ')' is found, an element is popped from the stack to represent matching it with its corresponding opening parenthesis. Non-parenthesis characters are ignored. The solution includes error handling that checks for unbalanced parentheses (though the problem guarantees valid input), returning -1 if there are mismatched parentheses. The maximum depth tracked throughout the traversal is returned as the final answer.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-13 01:29 UTC
- Runtime: 4 ms
- Memory: 8 MB
- Language: C++
