# Number of 1 Bits

**Difficulty:** Easy
**Tags:** bit-manipulation, bitwise-operations

## Problem

Given a positive integer, count how many bits are set to 1 in its binary representation. The input is constrained to be between 1 and 2^31 - 1, meaning it fits in a 32-bit signed integer.

## Approach

The solution iterates through all 32 bit positions of the integer. For each position from 0 to 31, it right-shifts the number by that position and performs a bitwise AND with 1 to isolate the least significant bit. This effectively checks whether the bit at that position is set. Each time a 1-bit is found, it increments a counter. After examining all 32 positions, the accumulated count is returned.

This is a straightforward bit-checking approach that examines every bit position regardless of the actual number of set bits. The key insight is that right-shifting by `x` positions moves the bit at position `x` to the least significant position, where `& 1` can test it.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-18 08:36 UTC
- Runtime: 0 ms
- Memory: 7.9 MB
- Language: C++
