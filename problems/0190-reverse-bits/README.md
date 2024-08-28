# Reverse Bits

**Difficulty:** Easy
**Tags:** bit-manipulation, bitwise-operations

## Problem

Given a 32-bit unsigned integer, reverse the order of its bits and return the resulting integer. The input is guaranteed to be even and within the range [0, 2^31 - 2], meaning we're working with a fixed 32-bit representation where bit positions need to be mirrored (bit 0 becomes bit 31, bit 1 becomes bit 30, etc.).

## Approach

The solution iterates through all 32 bit positions of the input number. For each position `i` from 0 to 31, it extracts the bit at position `i` using a right shift and bitwise AND operation (`(n >> i) & 1`). This extracted bit is then placed at the mirrored position `(31 - i)` in the result by left-shifting it and adding to the accumulator. The process builds up the reversed result bit by bit, with each iteration contributing one bit to its correct reversed position. After processing all 32 positions, the fully reversed bit pattern is returned.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-28 05:37 UTC
- Runtime: 4 ms
- Memory: 7.4 MB
- Language: C++
