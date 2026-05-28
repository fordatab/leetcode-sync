# Maximum Nesting Depth of the Parentheses

**Difficulty:** Easy
<<<<<<< HEAD
**Tags:** stack, string, parentheses

## Problem

Given a string containing digits, arithmetic operators, and parentheses that form a valid parentheses expression, determine the maximum nesting depth of the parentheses. The nesting depth is the greatest number of open parentheses that are simultaneously active at any point while traversing the string. The string length is at most 100 characters and is guaranteed to have balanced parentheses.

## Approach

The solution uses a stack to track open parentheses as it scans through the string character by character. When an opening parenthesis '(' is encountered, it's pushed onto the stack, and the current stack size is compared with the running maximum depth, updating the maximum if necessary. When a closing parenthesis ')' is found, an element is popped from the stack to represent matching it with its corresponding opening parenthesis. Non-parenthesis characters are ignored. The solution includes error handling that checks for unbalanced parentheses (though the problem guarantees valid input), returning -1 if there are mismatched parentheses. The maximum depth tracked throughout the traversal is returned as the final answer.
=======
**Tags:** string, stack, counting

## Problem

Given a string containing digits, operators, and parentheses (guaranteed to be a valid parentheses string), determine the maximum nesting depth of the parentheses. The nesting depth is the deepest level at which parentheses are nested within each other. The string length is between 1 and 100 characters.

## Approach

The solution uses a counter-based approach to track parenthesis depth. It iterates through each character in the string once, maintaining a running count of open brackets. When an opening parenthesis is encountered, the counter increments; when a closing parenthesis is found, it decrements. Throughout the traversal, the solution tracks the maximum value this counter reaches, which represents the deepest nesting level. This works because at any point in a valid parentheses string, the count of unmatched opening brackets equals the current nesting depth.
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Complexity

- **Time:** O(n)
<<<<<<< HEAD
- **Space:** O(n)

## Stats

- Submitted: 2024-07-13 01:29 UTC
- Runtime: 4 ms
- Memory: 8 MB
=======
- **Space:** O(1)

## Stats

- Submitted: 2026-04-22 04:58 UTC
- Runtime: 0 ms
- Memory: 8.3 MB
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
