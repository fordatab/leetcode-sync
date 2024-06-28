# Valid Parentheses

**Difficulty:** Easy
**Tags:** stack, string, ascii-arithmetic

## Problem

Given a string containing only bracket characters (parentheses, square brackets, and curly braces), determine whether the brackets are properly matched and nested. Each opening bracket must have a corresponding closing bracket of the same type, and they must be closed in the correct order. The string length can be up to 10,000 characters.

## Approach

The solution uses a stack to track opening brackets as they're encountered. When iterating through each character:

- If the character is an opening bracket ('(', '[', or '{'), it's pushed onto the stack
- If the character is a closing bracket, the code checks if the stack is empty (which would mean no matching opening bracket exists). If not empty, it uses ASCII value arithmetic to verify matching: it checks if the top of the stack is 1 or 2 less than the current closing bracket's ASCII value (this works because '(' and ')' differ by 1, '[' and ']' differ by 2, and '{' and '}' differ by 2)
- If a mismatch is found or the stack is empty when a closing bracket appears, the function returns false
- After processing all characters, the function returns true only if the stack is empty, ensuring all opening brackets were matched

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-28 04:26 UTC
- Runtime: 3 ms
- Memory: 7.7 MB
- Language: C++
