# Valid Parentheses

**Difficulty:** Easy
**Tags:** stack, string, matching

## Problem

Given a string containing only bracket characters (parentheses, square brackets, and curly braces), determine whether the brackets are properly balanced and nested. Each opening bracket must be closed by a matching closing bracket in the correct order, and every closing bracket must have a corresponding opening bracket of the same type. The string length can be up to 10,000 characters.

## Approach

The solution uses a stack-based approach to track opening brackets. It allocates a character array as a stack with size equal to the input string length, using an integer `top` as the stack pointer (initialized to -1 for an empty stack).

The algorithm iterates through each character in the string:
- When encountering an opening bracket ('(', '{', or '['), it pushes the character onto the stack by incrementing `top` and storing the character.
- When encountering a closing bracket, it first checks if the stack is empty (returning false if so). Then it verifies that the top of the stack contains the matching opening bracket. If matched, it pops from the stack by decrementing `top`; otherwise, it returns false.

After processing all characters, the function returns true only if the stack is empty (`top == -1`), ensuring all opening brackets were properly closed.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2023-08-03 22:22 UTC
- Runtime: 2 ms
- Memory: 5.8 MB
- Language: C
