# Power of Four

**Difficulty:** Easy
**Tags:** bit-manipulation, math, number-theory

## Problem

Determine whether a given integer is a power of four (4^x for some integer x). The input can be any 32-bit signed integer, including negative numbers and zero. The challenge encourages a solution without loops or recursion.

## Approach

The solution uses bitwise operations and modular arithmetic to check three conditions without iteration:

1. First, it rejects non-positive numbers since powers of four are always positive.
2. Next, it verifies that n is a power of two using the bitwise trick `(n & (n - 1)) == 0`, which is true only when n has exactly one bit set in its binary representation.
3. Finally, it distinguishes powers of four from other powers of two by checking if `(n - 1) % 3 == 0`. This works because powers of four follow the pattern 4^x = (3+1)^x, which means 4^x - 1 is always divisible by 3, while powers of two that aren't powers of four (like 2, 8, 32) don't satisfy this property.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-17 04:20 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
