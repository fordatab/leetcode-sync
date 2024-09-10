# A Number After a Double Reversal

**Difficulty:** Easy
**Tags:** math, modulo-arithmetic, edge-case-handling

## Problem

Given a non-negative integer, determine whether reversing it twice (where leading zeros are dropped after each reversal) yields the original number. The input ranges from 0 to 10^6. The key insight is recognizing when trailing zeros cause information loss during the first reversal.

## Approach

The solution uses a mathematical shortcut instead of performing actual reversals. It recognizes that a number survives double reversal if and only if it either equals zero or doesn't end in zero. This is because any trailing zeros become leading zeros after the first reversal and are dropped, making it impossible to recover the original number.

The code first checks if the input is exactly zero (a special case that always returns to itself). For all other numbers, it tests whether the number is not divisible by 10 using the modulo operator. If `num % 10 != 0`, the number has no trailing zeros and will survive both reversals intact.

This approach avoids the computational overhead of actually reversing the digits twice, instead solving the problem through direct mathematical observation.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-10 06:59 UTC
- Runtime: 3 ms
- Memory: 7.3 MB
- Language: C++
