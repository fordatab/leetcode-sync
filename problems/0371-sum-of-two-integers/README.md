# Sum of Two Integers

**Difficulty:** Medium
**Tags:** bit-manipulation, recursion, math

## Problem

Given two integers within the range -1000 to 1000, compute their sum without using addition or subtraction operators. The solution must rely on bitwise operations or other mechanisms to achieve the result.

## Approach

The solution uses bitwise operations to simulate binary addition through recursion.

- The base case checks if either operand is zero; if so, it returns the other operand using bitwise OR (which works correctly when one is zero).

- For the recursive case, it computes two values: (1) `a ^ b` calculates the sum without carries (XOR adds bits that don't both equal 1), and (2) `(a & b) << 1` calculates the carry bits (AND finds where both bits are 1, then left-shift moves carries to the next position).

- The function recursively calls itself with these two values, effectively breaking down the addition into simpler steps until no carries remain (when one operand becomes zero).

- This mirrors how binary addition works at the hardware level: add corresponding bits, then propagate carries leftward until complete.

## Complexity

- **Time:** O(log max(|a|, |b|))
- **Space:** O(log max(|a|, |b|))

## Stats

- Submitted: 2024-08-30 02:48 UTC
- Runtime: 0 ms
- Memory: 7.2 MB
- Language: C++
