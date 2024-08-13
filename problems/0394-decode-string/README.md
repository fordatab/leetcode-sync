# Decode String

**Difficulty:** Medium
**Tags:** stack, string, recursion

## Problem

Given a string with encoded patterns of the form k[substring], return the fully decoded string where each bracketed substring is repeated k times. The encoding can be nested, and the input is guaranteed to be well-formed with no extraneous whitespace. The input string length is at most 30, with repeat counts ranging from 1 to 300, and the output length will not exceed 10^5.

## Approach

The solution uses a stack-based approach to handle nested encodings. It maintains a current string being built and tracks the repeat count for the next bracketed section.

When encountering digits, the code accumulates them to form multi-digit numbers (e.g., '12' becomes 12). Upon hitting an opening bracket '[', it pushes the current string and repeat count onto the stack, then resets both to start processing the encoded section. When a closing bracket ']' is encountered, it pops the previous context from the stack, repeats the current string by the stored count, and appends it to the previous string, making this the new current string.

Regular letters are simply appended to the current string. This stack-based method naturally handles nesting because inner brackets are processed and resolved before outer ones, with each level of nesting corresponding to one stack frame.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-13 08:19 UTC
- Runtime: 0 ms
- Memory: 8.2 MB
- Language: C++
