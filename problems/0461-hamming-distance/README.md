# Hamming Distance

**Difficulty:** Easy
**Tags:** bit-manipulation, xor

## Problem

Given two non-negative integers x and y (both at most 2^31 - 1), determine how many bit positions differ when comparing their binary representations. This count of differing bit positions is known as the Hamming distance.

## Approach

The solution iterates through all 32 bit positions (sufficient for 32-bit integers). For each position, it extracts the corresponding bit from both x and y using right-shift and bitwise AND operations. It then applies XOR to these two bits: XOR returns 1 when the bits differ and 0 when they match. By accumulating these XOR results across all 32 positions, the code counts the total number of differing bits. This straightforward bit-by-bit comparison approach works because XOR naturally identifies positions where bits don't match.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 04:25 UTC
- Runtime: 0 ms
- Memory: 7.5 MB
- Language: C++
