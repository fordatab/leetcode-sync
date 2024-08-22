# Complement of Base 10 Integer

**Difficulty:** Easy
**Tags:** bit-manipulation, bitwise-xor, bitmask

## Problem

Given a non-negative integer n (0 ≤ n < 10^9), compute its bitwise complement by flipping all bits in its binary representation. For instance, 5 in binary is "101", and flipping each bit yields "010" which is 2 in decimal. The complement operation only applies to the significant bits, not leading zeros.

## Approach

The solution constructs a bitmask with all 1s that matches the bit-length of the input number. Starting with `c = 1`, it repeatedly left-shifts `c` and adds 1 (`c = (c << 1) + 1`) until `c` is at least as large as `N`. This process builds a number like 1, 11, 111, 1111 in binary, creating a mask that covers all significant bits of `N`. Once the mask is ready, XORing `N` with this all-1s mask flips every bit in `N`, producing the complement. For example, if N=5 (binary 101), the loop builds c=7 (binary 111), and 5 XOR 7 = 2 (binary 010).

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-22 23:20 UTC
- Runtime: 0 ms
- Memory: 7.4 MB
- Language: C++
