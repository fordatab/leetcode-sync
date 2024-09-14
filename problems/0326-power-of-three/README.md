# Power of Three

**Difficulty:** Easy
**Tags:** math, number-theory, modulo-arithmetic

## Problem

Determine whether a given integer is an exact power of three (3^x for some integer x). The input is a 32-bit signed integer ranging from -2^31 to 2^31 - 1. Negative numbers and zero cannot be powers of three, and the solution should ideally avoid loops or recursion.

## Approach

This solution uses a mathematical property: if `n` is a power of three, then the largest power of three that fits in a 32-bit signed integer (which is 3^19 = 1162261467) must be divisible by `n`. The code first performs boundary checks to eliminate invalid inputs: negative numbers, zero, and numbers larger than 3^19. For valid candidates, it checks whether the precomputed maximum power divides evenly by `n`. Since every power of three divides all higher powers of three, this modulo operation returns zero if and only if `n` itself is a power of three. This approach avoids loops and recursion entirely by leveraging the mathematical relationship between powers of the same base.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 08:39 UTC
- Runtime: 7 ms
- Memory: 8.5 MB
- Language: C++
