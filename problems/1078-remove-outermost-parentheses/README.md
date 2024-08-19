# Remove Outermost Parentheses

**Difficulty:** Easy
**Tags:** stack, string, parentheses

## Problem

Given a valid parentheses string, identify all primitive (non-decomposable) balanced parentheses substrings within it, then remove the outermost pair of parentheses from each primitive substring and concatenate the results. The input string length can be up to 100,000 characters and consists only of '(' and ')' characters.

## Approach

The solution uses a stack to track nesting depth while iterating through the string. For each opening parenthesis, if the stack is already non-empty (meaning we're inside a primitive substring), the character is added to the result string; then the character is pushed onto the stack. For each closing parenthesis, if the stack has more than one element (meaning we're not at the outermost level of the current primitive), the character is added to the result; then a character is popped from the stack. This approach effectively identifies the boundaries of each primitive substring by monitoring when the stack becomes empty (end of a primitive) and when it transitions from empty to non-empty (start of a primitive), skipping the outermost parentheses of each primitive segment.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-19 06:12 UTC
- Runtime: 5 ms
- Memory: 8.3 MB
- Language: C++
